#include <iostream>
#include "MySet.h"

int main() {
    std::cout << "=== 1 (single) ===" << std::endl;
    MySet<int> set1, set2;

    set1.add_element(1);
    set1.add_element(4);
    set1.add_element(5);
    set1.add_element(6);

    set2.add_element(1);
    set2.add_element(2);
    set2.add_element(3);
    set2.add_element(4);

    std::cout << "Set1: " << set1 << std::endl;
    std::cout << "Set2: " << set2 << std::endl;

    std::cout << "Объединение (Set1 + Set2): " << (set1 + set2) << std::endl;
    std::cout << "Пересечение (Set1 * Set2): " << (set1 * set2) << std::endl;
    std::cout << "Разность (Set1 - Set2): " << (set1 - set2) << std::endl;

    MySet<int> set3 = set1;
    std::cout << "Set3 = Set1: " << set3 << std::endl;

    set3 += set2;
    std::cout << "Set3 += Set2: " << set3 << std::endl;

    set3 -= set1;
    std::cout << "Set3 -= Set1: " << set3 << std::endl;

    set3 *= set2;
    std::cout << "Set3 *= Set2: " << set3 << std::endl;

    std::cout << "Set1 == Set2: " << (set1 == set2 ? "true" : "false") << std::endl;

    std::cout << "\n=== 2 (double) ===" << std::endl;
    MySet<double> dset1, dset2;

    dset1.add_element(1.1);
    dset1.add_element(4.4);
    dset1.add_element(5.5);
    dset1.add_element(6.6);

    dset2.add_element(1.1);
    dset2.add_element(2.2);
    dset2.add_element(3.3);
    dset2.add_element(4.4);

    std::cout << "DSet1: " << dset1 << std::endl;
    std::cout << "DSet2: " << dset2 << std::endl;

    std::cout << "Объединение (DSet1 + DSet2): " << (dset1 + dset2) << std::endl;
    std::cout << "Пересечение (DSet1 * DSet2): " << (dset1 * dset2) << std::endl;
    std::cout << "Разность (DSet1 - DSet2): " << (dset1 - dset2) << std::endl;

    std::cout << "\n=== 3 (char) ===" << std::endl;
    MySet<char*> sset1, sset2;

    char str1[] = "apple";
    char str2[] = "banana";
    char str3[] = "cherry";
    char str4[] = "date";
    char str5[] = "apple";
    char str6[] = "fig";
    char str7[] = "grape";
    char str8[] = "date";

    sset1.add_element(str1);
    sset1.add_element(str2);
    sset1.add_element(str3);
    sset1.add_element(str4);

    sset2.add_element(str5);
    sset2.add_element(str6);
    sset2.add_element(str7);
    sset2.add_element(str8);

    std::cout << "SSet1: " << sset1 << std::endl;
    std::cout << "SSet2: " << sset2 << std::endl;

    std::cout << "Объединение (SSet1 + SSet2): " << (sset1 + sset2) << std::endl;
    std::cout << "Пересечение (SSet1 * SSet2): " << (sset1 * sset2) << std::endl;
    std::cout << "Разность (SSet1 - SSet2): " << (sset1 - sset2) << std::endl;

    return 0;
}
