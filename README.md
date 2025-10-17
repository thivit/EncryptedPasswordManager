# EncryptedPasswordManager (C++ / Qt Widgets)
A simple C++ password manager that encrypts passwords before storing them.

## Features
- Encrypt / decrypt text using a key.
- Append results to a csv, only storing encrypted passwords.
- Minimal Qt Widgets GUI (mode dropdown, input textbox, key textbox, output view).

## Project Structure
```
.
├─ Data/               # storage (service, username, encrypted password)
├─ Include/            # headers (Cipher.hpp, FileManager.hpp)
├─ Source/             # sources (Main.cpp, Cipher.cpp, FileManager.cpp)
├─ install_qt.sh       # Ubuntu: installs build tools + Qt5 dev
├─ Makefile            # minimal build (uses pkg-config for Qt)
└─ README.md
```

## Prerequisites (Ubuntu)
If Qt5 dev files aren’t installed, run:
```bash
chmod +x ./install_qt.sh
./install_qt.sh
```

## Run (First-time build)
```bash
make run
```

## Run (After build)
```bash
./EncryptedPasswordManager
```
