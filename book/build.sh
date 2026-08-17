#!/usr/bin/env bash
# Assemble the BITH132 Field Guide and render it to a single PDF.
#
#   front matter (book/front/*.html, filename order)
# + chapters      (book/chapters/*.html, filename order)
# + back matter   (inline, below)
# wrapped in one HTML document with book/style.css inlined, then handed to
# wkhtmltopdf with an auto table-of-contents, a running header, and footer
# page numbers.
#
# Output: "BITH132 - The Field Guide.pdf" at the repo root.
# Requires: wkhtmltopdf on PATH. Everything is local; no network references.

set -euo pipefail

# --- locate paths (script lives in book/) -------------------------------
BOOK_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$BOOK_DIR/.." && pwd)"
OUT="$REPO_ROOT/BITH132 - The Field Guide.pdf"

command -v wkhtmltopdf >/dev/null 2>&1 || {
  echo "error: wkhtmltopdf not found on PATH" >&2; exit 1
}

WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
BODY="$WORK/book.html"

# --- assemble the single HTML document ----------------------------------
{
  echo '<!DOCTYPE html>'
  echo '<html lang="en"><head>'
  echo '<meta charset="utf-8">'
  echo '<title>BITH132 - The Field Guide</title>'
  echo '<style>'
  cat "$BOOK_DIR/style.css"
  echo '</style>'
  echo '</head><body>'

  # front matter, in filename order
  for f in "$BOOK_DIR"/front/*.html; do
    [ -e "$f" ] || continue
    cat "$f"; echo
  done

  # chapters, in filename order (NN- prefix guarantees order)
  shopt -s nullglob
  for f in "$BOOK_DIR"/chapters/*.html; do
    cat "$f"; echo
  done
  shopt -u nullglob

  # back matter
  cat <<'BACK'
<section class="chapter">
  <p class="eyebrow">Back matter</p>
  <h1>Colophon</h1>
  <div class="idea">
    <p>The BITH132 Field Guide is assembled from self-contained HTML fragments
    by <code>book/build.sh</code> and rendered with wkhtmltopdf. Every diagram
    is inline SVG; nothing is fetched over a network. The fragment contract
    that governs each chapter lives in <code>book/README.md</code>.</p>
  </div>
</section>
BACK

  echo '</body></html>'
} > "$BODY"

# --- render -------------------------------------------------------------
# TOC is a positional sub-command placed before the page input.
# --enable-local-file-access lets the (local) HTML resolve any local asset.
wkhtmltopdf \
  --enable-local-file-access \
  --print-media-type \
  --page-size A4 \
  --margin-top 26mm \
  --margin-bottom 15mm \
  --margin-left 0mm \
  --margin-right 0mm \
  --header-spacing 4 \
  --header-html "$BOOK_DIR/header.html" \
  --footer-spacing 3 \
  --footer-html "$BOOK_DIR/footer.html" \
  toc \
  --xsl-style-sheet "$BOOK_DIR/toc.xsl" \
  "$BODY" \
  "$OUT"

echo "built: $OUT"
