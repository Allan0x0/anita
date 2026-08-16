#!/usr/bin/env bash
# Build the book, then zip the complete offline study pack into
# BITH132-Field-Guide-handoff.zip at the repo root.
set -euo pipefail

BOOK_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$BOOK_DIR/.." && pwd)"

bash "$BOOK_DIR/build.sh"

cd "$REPO_ROOT"
ZIP="BITH132-Field-Guide-handoff.zip"
rm -f "$ZIP"
zip -r "$ZIP" \
  index.html Weeks app setup \
  "BITH132 - The Field Guide.pdf"

echo "built: $REPO_ROOT/$ZIP"
