#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    Student(const std::string& name, int id) : name(name), studentID(id) {}

    void setGrades(const std::vector<int>& grades) {
        this->grades = grades;
    }

    double calculateAverageGrade() const {
        if (grades.empty()) {
            return 0.0;
        }

        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }

        return static_cast<double>(sum) / grades.size();
    }

    bool isPassing() const {
        return calculateAverageGrade() >= 60.0;
    }

    void displayInfo() const {
        std::cout << "Öğrenci Adı: " << name << std::endl;
        std::cout << "Öğrenci ID: " << studentID << std::endl;
        std::cout << "Notlar: ";
        for (int grade : grades) {
            std::cout << grade << " ";
        }
        std::cout << std::endl;
        std::cout << "Ortalama Not: " << calculateAverageGrade() << std::endl;
        std::cout << "Geçme Durumu: " << (isPassing() ? "Geçti" : "Kaldı") << std::endl;
        std::cout << "------------------------------------" << std::endl;
    }

private:
    std::string name;
    int studentID;
    std::vector<int> grades;
};

int main() {
    // Öğrenci nesneleri oluştur
    Student student1("Ali", 101);
    Student student2("Ayşe", 102);
    setlocale(LC_ALL, "Turkish");
    // Notları ayarla
    student1.setGrades({ 75, 80, 92 });
    student2.setGrades({ 55, 60, 48 });

    // Bilgileri ekrana yazdır
    student1.displayInfo();
    student2.displayInfo();

    return 0;
}
