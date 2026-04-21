#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Notification {
protected:
    string recipient;
    string message;

public:
    Notification(const string& recipient, const string& message)
        : recipient(recipient), message(message) {}

    virtual ~Notification() {}

    virtual void send() {
        cout << "Sending generic notification to " << recipient << endl;
    }
};

class EmailNotification : public Notification {
    string subject;

public:
    EmailNotification(const string& recipient, const string& message,
                      const string& subject)
        : Notification(recipient, message), subject(subject) {}

    void send() override {
        cout << "Sending EMAIL to " << recipient
             << " | Subject: " << subject << endl;
    }
};

class SMSNotification : public Notification {
    string phoneNumber;

public:
    SMSNotification(const string& recipient, const string& message,
                    const string& phoneNumber)
        : Notification(recipient, message), phoneNumber(phoneNumber) {}

    void send() override {
        cout << "Sending SMS to " << phoneNumber
             << " | Message: " << message << endl;
    }
};

class PushNotification : public Notification {
    string deviceToken;

public:
    PushNotification(const string& recipient, const string& message,
                     const string& deviceToken)
        : Notification(recipient, message), deviceToken(deviceToken) {}

    void send() override {
        cout << "Sending PUSH to device " << deviceToken.substr(0, 8)
             << "... | Alert: " << message << endl;
    }
};

int main() {
    vector<unique_ptr<Notification>> notifications;
    notifications.push_back(make_unique<EmailNotification>(
        "alice@example.com", "Your order shipped!", "Order Update"));
    notifications.push_back(make_unique<SMSNotification>(
        "Bob", "Code: 482910", "+1-555-0123"));
    notifications.push_back(make_unique<PushNotification>(
        "Charlie", "New message", "d8a3f4b2c1e5a9b7"));

    for (auto& n : notifications) {
        n->send();
    }
    return 0;
}