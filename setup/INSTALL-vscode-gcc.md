# Set up your laptop to write C (Windows + Mac)

You do this **once per machine**. Takes ~15 minutes. Ask for help if a step fails —
don't fight it alone.

You need two things:
1. **VS Code** — the editor you type code in.
2. **gcc** — the compiler that turns your C into a running program.

---

## Windows

### 1. Install VS Code
- Go to https://code.visualstudio.com → **Download for Windows** → run the installer.
- Tick **"Add to PATH"** if it asks. Click through the defaults.

### 2. Install gcc (via MSYS2)
- Go to https://www.msys2.org → download the installer → run it (accept defaults).
- When it finishes, a black terminal opens. Type this and press Enter:
  ```
  pacman -S mingw-w64-ucrt-x86_64-gcc
  ```
  Press Enter again to accept, wait for it to finish.
- Add gcc to your PATH:
  - Windows Search → "environment variables" → **Edit the system environment variables**
  - **Environment Variables** → under *User variables* select **Path** → **Edit** → **New**
  - Paste: `C:\msys64\ucrt64\bin`
  - **OK** out of every window.

### 3. Check it worked
- Open a **new** Command Prompt (search "cmd"). Type:
  ```
  gcc --version
  ```
- You should see a version number. If you see "not recognized", the PATH step didn't
  take — reopen Command Prompt, or ask for help.

---

## Mac

### 1. Install VS Code
- Go to https://code.visualstudio.com → **Download for Mac** → drag it to Applications.

### 2. Install gcc (via Xcode tools)
- Open **Terminal** (Search → "Terminal"). Type:
  ```
  xcode-select --install
  ```
- A box pops up → **Install** → wait. (This gives you `clang`, which runs C exactly
  like gcc for our purposes. When notes say `gcc`, `clang` works the same.)

### 3. Check it worked
- In Terminal, type:
  ```
  gcc --version
  ```
- You should see a version number.

---

## VS Code: the C extension (both machines)

- Open VS Code → click the **Extensions** icon on the left (four squares).
- Search **"C/C++"** (by Microsoft) → **Install**.

---

## How you'll run a program every day

1. Open your code folder in VS Code (**File → Open Folder** → your Google Drive study folder).
2. Open a terminal inside VS Code: **Terminal → New Terminal**.
3. To compile and run a file called `hello.c`:
   ```
   gcc hello.c -o hello
   ./hello
   ```
   - On Windows, if `./hello` doesn't work, type `hello` (or `.\hello.exe`).
   - `gcc hello.c -o hello` = "compile hello.c into a program named hello".
   - `./hello` = "run it".

If it prints what you expected — you're done. That's the whole loop, every day.
