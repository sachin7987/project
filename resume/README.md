# Deedy Resume (OpenFonts) — Sachin Rai

A one-page, two-column résumé built with the **Deedy** LaTeX template
(OpenFonts variant by [Debarghya Das](https://github.com/deedydas/Deedy-Resume)).
It uses the free **Lato** and **Raleway** font families, so it compiles on
Linux/Windows/macOS with **XeLaTeX** — no proprietary fonts required.

## Files

| File | Purpose |
| --- | --- |
| `deedy-resume-openfont.cls` | The document class. Defines all colours, fonts and layout commands. You normally never edit this. |
| `resume.tex` | Sachin Rai's résumé — a worked example of every command. |
| `ghanshyam.tex` | Ghanshyam Rai's résumé — a second worked example (BBA / finance profile). |
| `template.tex` | A blank, commented skeleton. Copy it to start a new résumé. |
| `fonts/lato/` | Lato `.ttf` weights (Hairline, Light, Regular, Bold + italics). |
| `fonts/raleway/` | Raleway `.otf` weights (ExtraLight, Medium, …). |
| `resume.pdf` | The compiled output. |

## Build

This template **must** be compiled with XeLaTeX (it uses `fontspec` to load
the bundled fonts by file path).

```bash
xelatex resume.tex        # run twice so hyperlinks/outline settle
xelatex resume.tex
```

Requirements: a TeX distribution with XeLaTeX and the packages `fontspec`,
`geometry`, `hyperref`, `titlesec`, `xcolor`, `textpos`, `isodate`, `cite`,
`fancyhdr`. On Debian/Ubuntu:

```bash
sudo apt-get install texlive-xetex texlive-fonts-recommended texlive-latex-extra
```

Or paste `resume.tex` + `deedy-resume-openfont.cls` + the `fonts/` folder into
[Overleaf](https://overleaf.com) and set the compiler to **XeLaTeX**.

## How the template works

The `.cls` file only provides *styling*. Your `.tex` file provides *content*
and arranges it into two columns using `minipage`.

### Structure of a document

```latex
\documentclass[]{deedy-resume-openfont}
\usepackage{fancyhdr}\pagestyle{fancy}\fancyhf{}
\begin{document}
\lastupdated                         % "Last Updated on <date>" (top-right)
\namesection{First}{Last}{contact}   % big centered name + contact line

\begin{minipage}[t]{0.33\textwidth}  % LEFT column (narrow)
  ... short lists: Education, Skills, Coursework ...
\end{minipage}
\hfill
\begin{minipage}[t]{0.66\textwidth}  % RIGHT column (wide)
  ... prose: Experience, Projects, Achievements ...
\end{minipage}
\end{document}
```

### Commands provided by the class

| Command | Renders as |
| --- | --- |
| `\namesection{First}{Last}{info}` | Large centered name; `info` is the contact/subtitle line under it. |
| `\section{Title}` | Grey, uppercased section heading (e.g. EDUCATION). |
| `\subsection{Title}` | Bold black sub-heading on its own line (e.g. a school name). |
| `\runsubsection{Title}` | Same bold sub-heading but *inline*, so a `\descript` can follow on the same line. |
| `\descript{Text}` | Small-caps descriptor (e.g. a degree or a role, usually prefixed `\| `). |
| `\location{Text}` | Grey line for dates/locations. |
| `\sectionsep` | Adds vertical space between blocks. |
| `tightemize` environment | Bullet list with tight spacing (use instead of `itemize`). |
| `\textbullet{}` | The " " dot used to separate inline items (skills, tech stacks). |

Colours (`headings`, `subheadings`, `primary`, `date`) and margins are defined
at the top of the `.cls` and can be tweaked there.

## Generating a different résumé

1. Copy the skeleton: `cp template.tex john.tex`.
2. Replace every `<...>` placeholder with real content.
3. Move short, scannable content (education, skills, coursework) to the **left**
   `0.33` minipage and detailed prose (experience, projects) to the **right**
   `0.66` minipage.
4. Compile: `xelatex john.tex` (twice).

### Tips

- Keep it to **one page**. If content overflows to page 2, shorten bullets or
  move a block to the other column — the template does not auto-balance columns.
- Use `\runsubsection{Company}\descript{| Role}\location{Dates | City}` for each
  job, followed by a `tightemize` list of achievements.
- Put `\vspace{\topsep}` before the *first* `tightemize` in the right column to
  fix a small extra-space quirk (see `resume.tex`).
- To add a font weight, drop the file into `fonts/lato` or `fonts/raleway` and
  reference it with `\fontspec[Path = fonts/lato/]{<FileNameWithoutExtension>}`.

## Fonts & licence

Lato and Raleway are licensed under the SIL Open Font License and are bundled
here for convenience. The Deedy template is released under Apache 2.0 /
CC-BY-3.0 by Debarghya Das.
