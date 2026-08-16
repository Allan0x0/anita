# The BITH132 Field Guide - book pipeline

Single-PDF module book. Front matter + chapter fragments + back matter get
assembled and rendered to `BITH132 - The Field Guide.pdf` at the repo root by
one script.

## Build

```
bash book/build.sh
```

Requires `wkhtmltopdf` on `PATH` (tested with 0.12.6, patched Qt). No network,
no other dependencies. Output PDF is git-ignored (regenerable artifact).

The script:
1. Concatenates `book/front/*.html`, then `book/chapters/*.html`, then inline
   back matter, in filename order.
2. Wraps them in one HTML document with `book/style.css` inlined.
3. Renders with an auto table-of-contents (`toc` sub-command), a running header
   (`--header-center`), and footer page numbers (`--footer-center "[page]"`).

Filename order is the whole ordering mechanism. Two-digit prefixes
(`00-`, `01-`, ...) sort correctly, so the prefix IS the book order.

## Layout

```
book/
  style.css              print stylesheet (see "Styling constraints")
  build.sh               assemble + render
  front/                 front matter fragments, filename order
    01-cover.html
    02-howto-story.html
    03-cpp-primer.html
  chapters/              chapter fragments, filename order
    00-placeholder.html  delete once real chapters land
  README.md              this file
```

## Fragment contract

Every chapter is ONE file: `book/chapters/NN-slug.html`.

- `NN` = two-digit order prefix, assigned per issue (e.g. `04-the-queue.html`).
- The file is an HTML **fragment**: NO `<html>`, `<head>`, or `<body>` tags.
  `build.sh` supplies those and the `<style>`.
- Top element is `<section class="chapter">`. It gets a page break before it,
  so each chapter starts on a fresh page.
- The first heading inside becomes the chapter's table-of-contents entry. Use
  one `<h1>` for the chapter title.

### Self-contained, always

- No external references of any kind: no remote CSS, `<img src>`, web fonts,
  scripts, or `<link>`. The build renders offline and must stay that way.
- Diagrams are **inline SVG** (`<svg xmlns="...">...</svg>`) inside
  `<figure class="diagram">`. No image files.
- No em dashes or en dashes anywhere. Use commas, colons, semicolons, or
  parentheses.

### Code

- All code is C++ and must compile clean with `g++ -std=c++17`.
- Put listings in `<pre class="code"><code>...</code></pre>`.
- HTML-escape the C++: `<` becomes `&lt;`, `>` becomes `&gt;`, `&` becomes
  `&amp;`. So `#include <iostream>` is written
  `#include &lt;iostream&gt;`.
- Prefer complete, runnable programs (with `int main()`) so a reader can copy,
  compile, and run them. The build/verify step compiles every complete listing.

### Shared classes (from `style.css`) - use ONLY these

| Class | Element | Purpose |
|-------|---------|---------|
| `.chapter` | `<section>` | Chapter shell. Top element of every fragment. |
| `.hook` | `<div>` | The "why care" opener. One paragraph, before theory. |
| `.idea` | `<div>` | Plain explanation prose. |
| `figure.diagram` | `<figure>` | Wraps an inline `<svg>`, optional `<figcaption>`. |
| `pre.code` | `<pre><code>` | A C++ listing. |
| `.buildit` | `<div>` | Build-step callout (compile command + project step). |
| `.challenge` | `<div>` | Predict-output or spot-the-bug exercise. |
| `.exam-q` | `<div>` | Exam-style question. |
| `.exam-a` | `<div>` | Worked model answer, follows its `.exam-q`. |
| `.eyebrow` | `<p>` | Small uppercase label (e.g. inside `.buildit`). |
| `.page-break` | `<div>` | Force a page break where you need one. |

Do not invent new classes or use inline `style=` for layout. If a chapter needs
a style the contract lacks, add it to `style.css` in a shared, named class so
every chapter can use it, and document it in the table above.

### Skeleton to copy

```html
<section class="chapter">
  <p class="eyebrow">Chapter NN</p>
  <h1>Chapter title</h1>

  <div class="hook">
    <p>Why the reader should care, in one paragraph.</p>
  </div>

  <div class="idea">
    <p>The plain explanation.</p>
  </div>

  <figure class="diagram">
    <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 320 100" width="320" height="100">
      <!-- inline SVG only -->
    </svg>
    <figcaption>What the drawing shows.</figcaption>
  </figure>

  <pre class="code"><code>#include &lt;iostream&gt;

int main() {
    return 0;
}</code></pre>

  <div class="buildit">
    <p class="eyebrow">Build it</p>
    <p><code>g++ -std=c++17 file.cpp -o file &amp;&amp; ./file</code></p>
  </div>

  <div class="challenge">
    <p class="eyebrow">Challenge</p>
    <p>Predict the output, or spot the bug.</p>
  </div>

  <div class="exam-q">
    <p>Q. An exam-style question.</p>
  </div>
  <div class="exam-a">
    <p class="eyebrow">Model answer</p>
    <p>The worked answer.</p>
  </div>
</section>
```

## Styling constraints (why `style.css` looks old-fashioned)

`wkhtmltopdf` 0.12.6 renders with a patched Qt4 WebKit from around 2012. It does
**not** support:

- CSS custom properties (`var(--x)`) - so `style.css` uses literal hex colors.
- flexbox `gap`, or CSS grid - so layout is block + `table` only.

Keep new styles within those limits. Page-break helpers: `.page-break` forces a
break; `figure.diagram`, `pre.code`, `.buildit`, `.challenge`, and `.exam-a`
already carry `page-break-inside: avoid` so they will not split across pages.

Palette mirrors the `Weeks/*.html` web apps (light theme only for print):
drafting blue `#1D5A80`, timber `#B57C33`, ink `#16232B`, paper `#F6F8FA`.
