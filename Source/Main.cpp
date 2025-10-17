#include "../Include/Cipher.hpp"
#include "../Include/FileManager.hpp"
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QStackedWidget>
#include <QHBoxLayout>
#include "../Include/FileManager.hpp"
#include <QMessageBox>
using namespace std;

// To compile:
// g++ -fPIC Main.cpp Cipher.cpp FileManager.cpp -o main `pkg-config --cflags --libs Qt5Widgets`

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create stacked widget to manage pages
    QStackedWidget *stack = new QStackedWidget();

    // ========== FRONT PAGE ==========
    QWidget *frontPage = new QWidget();
    QVBoxLayout *frontLayout = new QVBoxLayout(frontPage);

    QLabel *header = new QLabel("Welcome to Encryption Password Management");
    header->setAlignment(Qt::AlignCenter);
    header->setStyleSheet("font-size: 18px; font-weight: bold; margin: 10px;");

    QPushButton *addCredential = new QPushButton("Add Credential");
    QPushButton *deleteCredential = new QPushButton("Delete Credential");
    QPushButton *findCredential = new QPushButton("Find Credential");
    QPushButton *updateCredential = new QPushButton("Update Credential");

    frontLayout->addWidget(header);
    frontLayout->addSpacing(20);
    frontLayout->addWidget(addCredential);
    frontLayout->addWidget(deleteCredential);
    frontLayout->addWidget(findCredential);
    frontLayout->addWidget(updateCredential);
    frontLayout->addStretch();

    //======== Check Credential page =======
    QWidget *checkCredentialPage = new QWidget();
    QVBoxLayout *checkCredentialLayout = new QVBoxLayout(checkCredentialPage);

    QLineEdit *ServiceInput = new QLineEdit();
    ServiceInput->setPlaceholderText("service");

    QPushButton *Check = new QPushButton("Check");
    QPushButton *backBtnCheck = new QPushButton("← Back to Home");

    checkCredentialLayout->addWidget(ServiceInput);
    checkCredentialLayout->addSpacing(20);
    checkCredentialLayout->addWidget(Check);
    checkCredentialLayout->addWidget(backBtnCheck);
    checkCredentialLayout->addStretch();

    //======== Find Credential page =======
    QWidget *FindCredentialPage = new QWidget();
    QVBoxLayout *FindCredentialLayout = new QVBoxLayout(FindCredentialPage);

    QLineEdit *ServiceFind = new QLineEdit();
    ServiceFind->setPlaceholderText("service");

    QWidget *resultContainer = new QWidget();
    QVBoxLayout *resultLayout = new QVBoxLayout(resultContainer);

    QPushButton *Find = new QPushButton("Find");
    QPushButton *backBtnFind = new QPushButton("← Back to Home");

    FindCredentialLayout->addWidget(ServiceFind);
    FindCredentialLayout->addSpacing(20);
    FindCredentialLayout->addWidget(Find);
    FindCredentialLayout->addWidget(backBtnFind);
    FindCredentialLayout->addWidget(resultContainer);
    FindCredentialLayout->addStretch();
    //===========Update Credential page ===========
    QWidget *updateCredentialPage = new QWidget();
    QVBoxLayout *updateCredentialLayout = new QVBoxLayout(updateCredentialPage);

    QLineEdit *ServiceUpdate = new QLineEdit();
    ServiceUpdate->setPlaceholderText("service");
    QLineEdit *usernameUpdate = new QLineEdit();
    usernameUpdate->setPlaceholderText("username");
    QLineEdit *passwordUpdate = new QLineEdit();
    passwordUpdate->setPlaceholderText("password");
    QComboBox *encryptionType = new QComboBox();
    encryptionType->addItem("Vigenere");
    encryptionType->addItem("Caesar Cipher");
    encryptionType->addItem("Rail Fence Cipher");
    QLineEdit *key = new QLineEdit();
    key->setPlaceholderText("Key");

    QPushButton *updateCredentialButton = new QPushButton("Update Credential");
    QPushButton *backBtnUpdate = new QPushButton("← Back to Home");

    updateCredentialLayout->addWidget(ServiceUpdate);
    updateCredentialLayout->addWidget(usernameUpdate);
    updateCredentialLayout->addWidget(passwordUpdate);
    updateCredentialLayout->addWidget(encryptionType);
    updateCredentialLayout->addWidget(key);
    updateCredentialLayout->addWidget(updateCredentialButton);
    updateCredentialLayout->addSpacing(20);
    updateCredentialLayout->addStretch();
    updateCredentialLayout->addWidget(backBtnUpdate);

    //===========Add Credential page ===========
    QWidget *AddCredentialPage = new QWidget();
    QVBoxLayout *AddCredentialLayout = new QVBoxLayout(AddCredentialPage);

    QLineEdit *ServiceAdd = new QLineEdit();
    ServiceAdd->setPlaceholderText("service");
    QLineEdit *usernameAdd = new QLineEdit();
    usernameAdd->setPlaceholderText("username");
    QLineEdit *passwordAdd = new QLineEdit();
    passwordAdd->setPlaceholderText("password");

    QLabel *encryptLabel = new QLabel("Encryption Type:");
    QComboBox *encryptCombo = new QComboBox();
    encryptCombo->addItem("Vigenere Cipher");
    encryptCombo->addItem("Caesar Cipher");
    encryptCombo->addItem("Rail Fence Cipher");
    QLineEdit *keyAdd = new QLineEdit();
    keyAdd->setPlaceholderText("Key");

    QPushButton *AddCredentialButton = new QPushButton("Add Credential");
    QPushButton *backBtnAdd = new QPushButton("← Back to Home");



    AddCredentialLayout->addWidget(ServiceAdd);
    AddCredentialLayout->addWidget(usernameAdd);
    AddCredentialLayout->addWidget(passwordAdd);

    AddCredentialLayout->addWidget(keyAdd);
    AddCredentialLayout->addWidget(encryptLabel);
    AddCredentialLayout->addWidget(encryptCombo);
    AddCredentialLayout->addWidget(AddCredentialButton);
    AddCredentialLayout->addSpacing(20);
    AddCredentialLayout->addStretch();
    AddCredentialLayout->addWidget(backBtnAdd);

    //===========Delete Credential page ===========
    QWidget *DeleteCredentialPage = new QWidget();
    QVBoxLayout *DeleteCredentialLayout = new QVBoxLayout(DeleteCredentialPage);

    QLineEdit *ServiceDelete = new QLineEdit();
    ServiceDelete->setPlaceholderText("service");

    QPushButton *DeleteCredentialButton = new QPushButton("Delete");
    QPushButton *backBtnDelete = new QPushButton("← Back to Home");

    DeleteCredentialLayout->addWidget(ServiceDelete);
    DeleteCredentialLayout->addWidget(DeleteCredentialButton);
    DeleteCredentialLayout->addSpacing(20);
    DeleteCredentialLayout->addStretch();
    DeleteCredentialLayout->addWidget(backBtnDelete);

    // ========== FEATURE PAGE (Encrypt/Decrypt UI) ==========
    QWidget *featurePage = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(featurePage);

    QComboBox *dropbox = new QComboBox();
    dropbox->addItem("Encrypt");
    dropbox->addItem("Decrypt");

    QLineEdit *input = new QLineEdit();
    input->setPlaceholderText("Enter plaintext or ciphertext");

    QLineEdit *key1 = new QLineEdit();
    key1->setPlaceholderText("Enter key");

    QTextEdit *res = new QTextEdit();
    res->setReadOnly(true);

    QPushButton *generateBtn = new QPushButton("Generate");

    layout->addWidget(new QLabel("Mode:"));
    layout->addWidget(dropbox);
    layout->addWidget(input);
    layout->addWidget(key1);
    layout->addWidget(res);
    layout->addWidget(generateBtn);

    // Add pages to stack
    stack->addWidget(frontPage);   // index 0
    stack->addWidget(featurePage); // index 1
    stack->addWidget(checkCredentialPage);
    stack->addWidget(updateCredentialPage);
    stack->addWidget(AddCredentialPage);
    stack->addWidget(DeleteCredentialPage);
    stack->addWidget(FindCredentialPage);

    // Show initial front page
    QWidget window;
    QVBoxLayout *mainLayout = new QVBoxLayout(&window);
    mainLayout->addWidget(stack);
    window.setWindowTitle("Encrypted Password Manager");
    window.resize(450, 300);
    window.show();

    // ========== CONNECTIONS ==========
    QObject::connect(addCredential, &QPushButton::clicked, [&]()
                     { stack->setCurrentWidget(checkCredentialPage); });
    QObject::connect(updateCredential, &QPushButton::clicked, [&]()
                     { stack->setCurrentWidget(updateCredentialPage); });
    QObject::connect(deleteCredential, &QPushButton::clicked, [&]()
                     { stack->setCurrentWidget(DeleteCredentialPage); });
    QObject::connect(findCredential, &QPushButton::clicked, [&]()
                     { stack->setCurrentWidget(FindCredentialPage); });

    auto goToFeaturePage = [stack]()
    { stack->setCurrentIndex(1); };

    // ======= Back buttons for each page ========
    QObject::connect(backBtnCheck, &QPushButton::clicked, [stack]()
                     { stack->setCurrentIndex(0); });
    QObject::connect(backBtnUpdate, &QPushButton::clicked, [stack]()
                     { stack->setCurrentIndex(0); });
    QObject::connect(backBtnAdd, &QPushButton::clicked, [stack]()
                     { stack->setCurrentIndex(0); });
    QObject::connect(backBtnDelete, &QPushButton::clicked, [stack]()
                     { stack->setCurrentIndex(0); });
    QObject::connect(backBtnFind, &QPushButton::clicked, [stack]()
                     { stack->setCurrentIndex(0); });

    QObject::connect(generateBtn, &QPushButton::clicked, [=]()
                     {
        QString choice = dropbox->currentText();
        string text = input->text().toStdString();
        string keyText = key1->text().toStdString();

        if (choice == "Encrypt") {
            string ciphertext = Cipher::vigenereEncrypt(text, keyText);
            res->setText(QString::fromStdString(ciphertext));
            FileManager::writeToFile("encrypted.txt", ciphertext);
        } else {
            string plaintext = Cipher::vigenereDecrypt(text, keyText);
            res->setText(QString::fromStdString(plaintext));
            FileManager::writeToFile("decrypted.txt", plaintext);
        } });

    QObject::connect(updateCredentialButton, &QPushButton::clicked, [=]()
                     {
                         string service = ServiceUpdate->text().toStdString();
                         string user = usernameUpdate->text().toStdString();
                         string pass = passwordUpdate->text().toStdString();
                         string ET = encryptionType->currentText().toStdString();
                         string k = key->text().toStdString();

                         if(service.empty() || user.empty() || pass.empty()){
                            QMessageBox::warning(nullptr,"Warning","Please fill in service, username, and password.");
                            return;
                         }
                        int selectedIndex = encryptionType->currentIndex();
                        if ((selectedIndex == 1 || selectedIndex == 2) && k.empty()) {
                            QMessageBox::warning(nullptr, "Warning", "Key cannot be empty for Caesar or Rail Fence cipher.");
                            return;
                        }
                        if ((selectedIndex == 1 || selectedIndex == 2) && !std::all_of(k.begin(), k.end(), ::isdigit)) {
                            QMessageBox::warning(nullptr, "Warning", "Key must be numeric for Caesar or Rail Fence cipher.");
                            return;
                        }
                        
                        Cipher cipher;
                        string encryptedPassword = cipher.Encrypt(pass, k, selectedIndex);

                        Credential newCred{service, user, encryptedPassword};

                        bool success = FileManager::updateCredential("Data/Data.txt", service, newCred);

                        if (success) {
                            QMessageBox::information(nullptr, "Success", "Credential updated successfully!");
                            stack->setCurrentWidget(frontPage);
                        } else {
                            QMessageBox::critical(nullptr, "Error", "Failed to update credential. Make sure the service exists in the file.");
                        } });

    QObject::connect(Check, &QPushButton::clicked, [=]()
                     {
                         string text = ServiceInput->text().toStdString();
                         bool found;
                         FileManager::findCredential("Data/Data.txt", text, found);
                             // Clear any previous message/buttons
                        QLayoutItem *item;
                        while ((item = checkCredentialLayout->takeAt(checkCredentialLayout->count() - 1)) != nullptr) {
                            if (item->widget() != backBtnFind && item->widget() != ServiceInput && item->widget() != Check)
                                delete item->widget();
                            delete item;
                        }
                        checkCredentialLayout->addSpacing(10);
                         if (found)
                         {
                             QLabel *alert = new QLabel("Credential found for this service. Do you want to update it?");
                             alert->setAlignment(Qt::AlignCenter);
                             alert->setStyleSheet("font-weight: bold; font-size: 14px; color: #333;");

                             QPushButton *option1 = new QPushButton("Yes");
                             QPushButton *option2 = new QPushButton("No");
                             option1->setStyleSheet(
                                "QPushButton { background-color: #4CAF50; color: white; font-weight: bold; padding: 6px 20px; border-radius: 6px; }"
                                "QPushButton:hover { background-color: #45a049; }");
                             option2->setStyleSheet(
                                "QPushButton { background-color: #f44336; color: white; font-weight: bold; padding: 6px 20px; border-radius: 6px; }"
                                "QPushButton:hover { background-color: #e53935; }");

                             checkCredentialLayout->addWidget(alert);
                             checkCredentialLayout->addWidget(option1);
                             checkCredentialLayout->addWidget(option2);


                            QObject::connect(option1, &QPushButton::clicked, [=]()
                            {
                                stack->setCurrentWidget(AddCredentialPage);
                            });

                            QObject::connect(option2, &QPushButton::clicked, [=]()
                            {
                                stack->setCurrentWidget(frontPage);
                            });

                             

                         }
                         else{
                            stack->setCurrentWidget(AddCredentialPage);
                         } });

    QObject::connect(Find, &QPushButton::clicked, [=]()
                     {
        string text = ServiceFind->text().toStdString();
        bool found;
        Credential cred = FileManager::findCredential("Data/Data.txt", text, found);

        // Clear old results
        QLayoutItem *item;
        while ((item = resultLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }

        if (found) {
            QLabel *alert = new QLabel("Credential found for this service.");
            alert->setAlignment(Qt::AlignCenter);
            alert->setStyleSheet("font-weight: bold; font-size: 14px; color: #333;");
            resultLayout->addWidget(alert);

            QLabel *svcLabel = new QLabel(QString::fromStdString("Service: " + cred.service));
            QLabel *userLabel = new QLabel(QString::fromStdString("Username: " + cred.username));
            QString masked = QString(cred.password.size(), QChar('*'));
            QLabel *passLabel = new QLabel("Password: " + masked);

            resultLayout->addWidget(svcLabel);
            resultLayout->addWidget(userLabel);
            resultLayout->addWidget(passLabel);
        } else {
            QLabel *alert = new QLabel("Credential not found!");
            alert->setAlignment(Qt::AlignCenter);
            alert->setStyleSheet("font-weight: bold; font-size: 14px; color: #d50505ff;");
            resultLayout->addWidget(alert);
        } });

    QObject::connect(AddCredentialButton, &QPushButton::clicked, [=]()
                     {
                        string service = ServiceAdd->text().toStdString();
                        string user = usernameAdd->text().toStdString();
                        string pass = passwordAdd->text().toStdString();
                        string ET = encryptCombo->currentText().toStdString();
                        string k = keyAdd->text().toStdString();

                        if (service.empty() || user.empty() || pass.empty()) {
                            QMessageBox::warning(AddCredentialPage, "Warning", "Please fill in service, username, and password.");
                            return;
                        }
                        
                        int selectedIndex = encryptCombo->currentIndex();
                        if ((selectedIndex == 1 || selectedIndex == 2) && k.empty()) {
                            QMessageBox::warning(nullptr, "Warning", "Key cannot be empty for Caesar or Rail Fence cipher.");
                            return;
                        }
                        if ((selectedIndex == 1 || selectedIndex == 2) && !std::all_of(k.begin(), k.end(), ::isdigit)) {
                            QMessageBox::warning(nullptr, "Warning", "Key must be numeric for Caesar or Rail Fence cipher.");
                            return;
                        }
                        Cipher cipher;
                        string encryptedPassword = cipher.Encrypt(pass, k, selectedIndex);

                        Credential newCred{service, user, encryptedPassword};
                        bool success = FileManager::saveCredential("Data/Data.txt", newCred);

                        if (success) {
                            QMessageBox::information(AddCredentialPage, "Success", "Credential added successfully!");
                            // Optionally clear inputs
                            ServiceAdd->clear();
                            usernameAdd->clear();
                            passwordAdd->clear();
                            keyAdd->clear();
                            encryptCombo->setCurrentIndex(0);
                        } else {
                            QMessageBox::critical(AddCredentialPage, "Error", "Failed to save credential.");
                        } });

    QObject::connect(DeleteCredentialButton, &QPushButton::clicked, [=]()
                     {
                        string service = ServiceDelete->text().toStdString();

                        if (service.empty()) {
                            QMessageBox::warning(DeleteCredentialPage, "Warning", "Please fill in service");
                            return;
                        }


                        // Credential newCred{service, user, pass};
                        bool success = FileManager::deleteCredential("Data/Data.txt", service);

                        if (success) {
                            QMessageBox::information(DeleteCredentialPage, "Success", "Credential deleted successfully!");
                            // Optionally clear inputs
                            ServiceAdd->clear();
                            usernameAdd->clear();
                            passwordAdd->clear();
                            keyAdd->clear();
                        } else {
                            QMessageBox::critical(DeleteCredentialPage, "Error", "Failed to save credential.");
                        } });
    return app.exec();
}
