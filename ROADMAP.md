# BITH132 — Data Structures & Algorithms — Study Plan

**Learner:** works full-time, time-poor, studies in stolen moments.
**Goal:** understand deeply + pass the ZOU exam. Learn by *building*.
**Spine project:** a **roof-truss helper app**, grown one unit at a time, in **C**.
**Themes for variety:** roof trussing (main), food/recipes, tourist attractions (drills).

---

## How it works (every single day)

- **Phone, 10–15 min:** one concept card + one diagram + a 2–3 question quiz. (the web app)
- **Laptop, 2–3×/week:** a "build step" that grows the truss app. (real C code)
- **1 day/week:** review, no new material. Catches up missed days, prevents burnout.

**Language:** pure **C** (not C++). The exam is graded in C. Pointers are unavoidable
(Units 4–7, 10 depend on them) — so we make them the *least scary* thing, with heavy
diagrams. A pointer = a nail pointing from one truss member to the next joint.

**Tools:** VS Code + gcc (MinGW on Windows, clang/gcc on Mac). Same setup both machines.
**Sync:** a Google Drive folder holds her code (works Win + Mac, offline-syncs).
**Materials:** one private web app (daily driver) + PDF/markdown notes (offline) + curated video links per unit.

---

## The 8-week calendar

| Wk | Units | Truss build step | Efficiency (Big-O) touch |
|----|-------|------------------|--------------------------|
| **0** | C on-ramp | print an ASCII truss, read a span, compute a height | — |
| **1** | 1 Arrays, 2 Strings | cut-list = array of member lengths; labels = strings; 2D = truss grid | count the loops |
| **2** | 3 Structs, 4 Pointers (start) | `Member {length, angle, type}`; truss = array of Members | — |
| **3** | 4 Pointers (finish), 5 Linked Lists | bill-of-materials as a linked list | why a list beats an array here |
| **4** | 6 Stacks, 7 Queues | saw-job **queue** (FIFO); offcut/undo **stack** (LIFO) | — |
| **5** | 8 Sorting, 9 Searching | sort cut-list by length (kill offcuts); find a member by spec | O(n²) vs O(n log n); binary search |
| **6** | 10 Trees | the truss **as a binary tree** (king-post); traversals = walk it | tree depth |
| **7** | Mock exam + review | finish + polish the app | full efficiency recap |

Pointers get 1.5 weeks (the hinge). All 10 units covered. Exam's two targets baked in:
**(1) pick the right structure**, **(2) analyse its efficiency**.

Week 7 has slack — if any unit scares her, we widen it and steal days from here.

---

## Build order (front-loaded)

1. This roadmap. ✅
2. **On-ramp week:** 6 daily micro-lessons + web-app shell + starter C files + setup guide.
3. **Unit 1** (Arrays).
4. Then roll one week at a time, tuning to how she's actually coping.

## Files (this folder)

```
ROADMAP.md            ← you are here
setup/                ← install guides (VS Code + gcc, Win + Mac)
onramp/               ← week 0 notes + starter C files
app/                  ← the web app (daily driver)
```
