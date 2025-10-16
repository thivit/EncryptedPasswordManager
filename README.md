# EncryptedPasswordManager (C++ / Qt Widgets)
A simple C++ password manager that encrypts passwords before storing them.

## Features
- Encrypt / decrypt text using a key.
- Append results to files for inspection:
  - `encrypted.txt` (encrypted output)
  - `decrypted.txt` (plaintext output)
- Minimal Qt Widgets GUI (mode dropdown, input textbox, key textbox, output view).

## Project Structure
```
.
├─ Include/            # headers (Cipher.hpp, FileManager.hpp)
├─ Source/             # sources (Main.cpp, Cipher.cpp, FileManager.cpp)
├─ install_qt.sh       # Ubuntu/Debian: installs build tools + Qt5 dev
├─ Makefile            # minimal build (uses pkg-config for Qt)
├─ encrypted.txt       # sample output file (created by the app)
├─ decrypted.txt       # sample output file (created by the app)
└─ README.md
```

## Prerequisites (Ubuntu/Debian)
If Qt5 dev files aren’t installed, run:
```bash
./scripts/install_qt.sh
```
## Build & Run
```bash
# build
make

# run
make run

# clean 
make clean
```

