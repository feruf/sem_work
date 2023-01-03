#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
const int maxBr = 30;

fstream fp;
const string fname = "fileF.dat";



struct member {
    int number;
    char name[50];
    int age;
    char sex;
    double bedr_o;
    double ram_o;
    double shiq_o;
    double pras_o;
    
};

void menu(member arr[], int& len, member gr1[], member gr2[], member gr3[], member gr4[], int& len1, int& len2, int& len3, int& len4);

void categ(member arr[], int len, member gr1[], member gr2[], member gr3[], member gr4[], int& len1, int& len2, int& len3, int& len4);
void outputCat(member gr1[], member gr2[], member gr3[], member gr4[], int len1, int len2, int len3, int len4);
void pobeditel(member gr1[], member gr2[], member gr3[], member gr4[], int len1, int len2, int len3, int len4);

void addd(member arr[], int& len);          //
void output(member arr[], int len);         //
void output_prop(member arr[], int len);
void minAge(member arr[], int len);         //
void searchName(member arr[], int len);     //
void sortAge(member arr[], int len);        //
void sortAgeName(member arr[], int len);    //
void searchAgeSex(member arr[], int len);   //
void zapis(member arr[], int len);          //
void chetene(member arr[], int& len);       //
void sortNizh(member arr[], int length);
void sortVuzh(member arr[], int length);
double formula(double bedr, double shiq, double pras, double ram);
void podmenu(member arr[], int& len, member gr1[], member gr2[], member gr3[], member gr4[], int& len1, int& len2, int& len3, int& len4);


void menu(member arr[], int& len, member gr1[], member gr2[], member gr3[], member gr4[], int& len1, int& len2, int& len3, int& len4)
{
    int choise;

    do {

        system("cls");

        cout << "Tova e menu, v koeto chrez vuvejdane na chislo, izbirate da izpulnite nqkoq ot zadadenite funkcii";


        cout << endl << "1. Dobavqne na uchastnici";
        cout << endl << "2. Izvejdane na uchastnicite v oformen vid";
        cout << endl << "3. Namirane i izvejdane na vsichki uchastnici s nai-malka vuzrast";
        cout << endl << "4. Tursene na uchastnik po ime";
        cout << endl << "5. Podrejdane na masiva ot uchastnici po vuzhodqsh red, sprqmo vuzrastta im";
        cout << endl << "6. Zapisvane na masiva v dvoichen fail";
        cout << endl << "7. Vuvejdane na masiva ot dvoichen fail";
        cout << endl << "8. Podmenu s dopulnitelni funkcii";
        cout << endl << "9. Kategorizirane na uchastnicite";
        cout << endl << "10. Izvejdane na spisuk ot uchastnici ot vsqka kategoriq";
        cout << endl << "11. Pobediteli";
        cout << endl << "0. Izhod";
        cout << endl;
        cin >> choise;
        cin.ignore();

        switch (choise)
        {
        case 1:

            cout << "Vuvejdane na uchastnici..." << endl;
            addd(arr, len);
            break;

        case 2:

            cout << "Izvejdane na uchastnicite..." << endl;
            output(arr, len);
            break;

        case 3:

            cout << "Izvejdane na uchastnik s minimalna vuzrast..." << endl;
            minAge(arr, len);
            break;

        case 4:

            cout << "Tursene na uchastnik po ime..." << endl;
            searchName(arr, len);
            break;

        case 5:

            cout << "Podrejdane na uchastnicite po narastvasht red, sprqmo vuzrastta im..." << endl;
            sortAge(arr, len);
            break;

        case 6:

            cout << "Zapisvane v dvoichen fail..." << endl;
            zapis(arr, len);
            break;

        case 7:

            cout << "Vuvejdane na masiva ot dvoichen fail..." << endl;
            chetene(arr, len);
            break;

        case 8:
            podmenu(arr, len, gr1, gr2, gr3, gr4, len1, len2, len3, len4);
            break;

        case 9:
            cout << "Kategorizirane..." << endl;
            categ(arr, len, gr1, gr2, gr3, gr4, len1, len2, len3, len4);
            break;

        case 10:
            cout << "Izvejdane na kategoriite..." << endl;
            outputCat(gr1, gr2, gr3, gr4, len1, len2, len3, len4);
            break;

        case 11:
            cout << "Pobeditel" << endl;
            pobeditel(gr1, gr2, gr3, gr4, len1, len2, len3, len4);
            break;

        case 0:
            cout << "Zapisvane v dvoichen fail..." << endl;
            zapis(arr, len);
            exit(0);
            break;

        default:
            system("cls");
            cout << "Greshno vuveden izbor..." << endl;
            break;
        }
        system("pause");


    } while (choise != 0);


}
void categ(member arr[], int len, member gr1[], member gr2[], member gr3[], member gr4[], int& len1, int& len2, int& len3, int& len4)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i].age >= 14 && arr[i].age <= 16)
        {
            gr1[len1] = arr[i];
            len1++;
        }
        if (arr[i].age >= 17 && arr[i].age <= 19)
        {
            gr2[len2] = arr[i];
            len2++;
        }
        if (arr[i].age >= 20 && arr[i].age <= 22)
        {
            gr3[len3] = arr[i];
            len3++;
        }
        if (arr[i].age >= 23 && arr[i].age <= 25)
        {
            gr4[len4] = arr[i];
            len4++;
        }
    }

}
void outputCat(member gr1[], member gr2[], member gr3[], member gr4[], int len1, int len2, int len3, int len4)
{
    if (len1 > 0)
    {
        cout << endl << "I grupa" << endl;
        output(gr1, len1);
    }
    else cout << endl << "Nqma uchastnici v I grupa!" << endl;

    if (len2 > 0)
    {
        cout << endl << "II grupa" << endl;
        output(gr2, len2);
    }
    else cout << endl << "Nqma uchastnici vuv II grupa!" << endl;

    if (len3 > 0)
    {
        cout << endl << "III grupa" << endl;
        output(gr3, len3);
    }
    else cout << endl << "Nqma uchastnici v III grupa!" << endl;

    if (len4 > 0)
    {
        cout << endl << "IV grupa" << endl;
        output(gr4, len4);
    }
    else cout << endl << "Nqma uchastnici v IV grupa!" << endl;

}
double formula(double bedr, double shiq, double pras, double ram)
{
    return bedr / (shiq + pras + ram);
}

void pobeditel(member gr1[], member gr2[], member gr3[], member gr4[], int len1, int len2, int len3, int len4)
{
    member win1[maxBr];
    int win1Br = 0;
    member win2[maxBr];
    int win2Br = 0;
    member win3[maxBr];
    int win3Br = 0;
    member win4[maxBr];
    int win4Br = 0;

    member gr1Nad[maxBr];
    int br1Nad = 0;
    member gr2Nad[maxBr];
    int br2Nad = 0;
    member gr3Nad[maxBr];
    int br3Nad = 0;
    member gr4Nad[maxBr];
    int br4Nad = 0;

    member gr1Pod[maxBr];
    int br1Pod = 0;
    member gr2Pod[maxBr];
    int br2Pod = 0;
    member gr3Pod[maxBr];
    int br3Pod = 0;
    member gr4Pod[maxBr];
    int br4Pod = 0;
    member winners[4];



    for (int i = 0; i < len1; i++)
    {
        if (formula(gr1[i].bedr_o, gr1[i].shiq_o, gr1[i].pras_o, gr1[i].ram_o) >= 0.54 && formula(gr1[i].bedr_o, gr1[i].shiq_o, gr1[i].pras_o, gr1[i].ram_o) <= 0.62)
        {
            win1[win1Br] = gr1[i];
            win1Br++;
        }
        if (formula(gr1[i].bedr_o, gr1[i].shiq_o, gr1[i].pras_o, gr1[i].ram_o) > 0.63)
        {
            gr1Nad[br1Nad] = gr1[i];
            br1Nad++;
        }
        if (formula(gr1[i].bedr_o, gr1[i].shiq_o, gr1[i].pras_o, gr1[i].ram_o) < 0.53)
        {
            gr1Pod[br1Pod] = gr1[i];
            br1Pod++;
        }
    }

    for (int i = 0; i < len2; i++)
    {
        if (formula(gr2[i].bedr_o, gr2[i].shiq_o, gr2[i].pras_o, gr2[i].ram_o) >= 0.54 && formula(gr2[i].bedr_o, gr2[i].shiq_o, gr2[i].pras_o, gr2[i].ram_o) <= 0.62)
        {
            win2[win2Br] = gr2[i];
            win2Br++;
        }
        if (formula(gr2[i].bedr_o, gr2[i].shiq_o, gr2[i].pras_o, gr2[i].ram_o) > 0.63)
        {
            gr2Nad[br2Nad] = gr2[i];
            br2Nad++;
        }
        if (formula(gr2[i].bedr_o, gr2[i].shiq_o, gr2[i].pras_o, gr2[i].ram_o) < 0.53)
        {
            gr2Pod[br2Pod] = gr2[i];
            br2Pod++;
        }
    }

    for (int i = 0; i < len3; i++)
    {
        if (formula(gr3[i].bedr_o, gr3[i].shiq_o, gr3[i].pras_o, gr3[i].ram_o) >= 0.54 && formula(gr3[i].bedr_o, gr3[i].shiq_o, gr3[i].pras_o, gr3[i].ram_o) <= 0.62)
        {
            win3[win3Br] = gr3[i];
            win3Br++;
        }
        if (formula(gr3[i].bedr_o, gr3[i].shiq_o, gr3[i].pras_o, gr3[i].ram_o) > 0.63)
        {
            gr3Nad[br3Nad] = gr3[i];
            br3Nad++;
        }
        if (formula(gr3[i].bedr_o, gr3[i].shiq_o, gr3[i].pras_o, gr3[i].ram_o) < 0.53)
        {
            gr3Pod[br3Pod] = gr3[i];
            br3Pod++;
        }

    }

    for (int i = 0; i < len4; i++)
    {
        if (formula(gr4[i].bedr_o, gr4[i].shiq_o, gr4[i].pras_o, gr4[i].ram_o) >= 0.54 && formula(gr4[i].bedr_o, gr4[i].shiq_o, gr4[i].pras_o, gr4[i].ram_o) <= 0.62)
        {
            win4[win4Br] = gr4[i];
            win4Br++;
        }
        if (formula(gr4[i].bedr_o, gr4[i].shiq_o, gr4[i].pras_o, gr4[i].ram_o) > 0.63)
        {
            gr4Nad[br4Nad] = gr4[i];
            br4Nad++;
        }
        if (formula(gr4[i].bedr_o, gr4[i].shiq_o, gr4[i].pras_o, gr4[i].ram_o) < 0.53)
        {
            gr4Pod[br4Pod] = gr4[i];
            br4Pod++;
        }
    }

    sortNizh(win1, win1Br);
    sortNizh(win2, win2Br);
    sortNizh(win3, win3Br);
    sortNizh(win4, win4Br);

    sortVuzh(gr1Nad, br1Nad);
    sortVuzh(gr2Nad, br2Nad);
    sortVuzh(gr3Nad, br3Nad);
    sortVuzh(gr4Nad, br4Nad);

    sortVuzh(gr1Pod, br1Pod);
    sortVuzh(gr2Pod, br2Pod);
    sortVuzh(gr3Pod, br3Pod);
    sortVuzh(gr4Pod, br4Pod);

    if (win1Br != 0)
    {
        cout << "Pobeditelite ot I grupa!" << endl;
        output_prop(win1, win1Br);
    }
    else cout << "Nqma pobediteli ot I grupa!" << endl;

    if (win2Br != 0)
    {
        cout << "Pobeditelite ot II grupa!" << endl;
        output_prop(win2, win2Br);
    }
    else cout << "Nqma pobediteli ot II grupa!" << endl;

    if (win3Br != 0)
    {
        cout << "Pobeditelite ot III grupa!" << endl;
        output_prop(win3, win3Br);
    }
    else cout << "Nqma pobediteli ot III grupa!" << endl;

    if (win4Br != 0)
    {
        cout << "Pobeditelite ot IV grupa!" << endl;
        output_prop(win4, win4Br);
    }
    else cout << "Nqma pobediteli ot IV grupa!" << endl;


    cout << "Ostanalite uchastnici ot I grupa" << endl;
    output_prop(gr1Nad, br1Nad);
    output_prop(gr1Pod, br1Pod);

    cout << "Ostanalite uchastnici ot II grupa" << endl;
    output_prop(gr2Nad, br2Nad);
    output_prop(gr2Pod, br2Pod);

    cout << "Ostanalite uchastnici ot III grupa" << endl;
    output_prop(gr3Nad, br3Nad);
    output_prop(gr3Pod, br3Pod);

    cout << "Ostanalite uchastnici ot IV grupa" << endl;
    output_prop(gr4Nad, br4Nad);
    output_prop(gr4Pod, br4Pod);

}
void addd(member arr[], int& len)
{
    //system("cls");

    double n;
    if (maxBr - len < 1)
    {
        cout << "Nqma poveche mesta v grupata";
        return;
    }

    cout << "V masiva ima " << maxBr - len << " svobodni mesta" << endl;

    do {
        cout << "Vuvedete cqlo chislo, v intervala [1;" << maxBr - len << "], ";
        cout << "broi na uchastnicite, koito iskate da vuvedete : ";
        cin >> n;
        cin.ignore();
    } while (n<1 || n>maxBr - len || n != (int)n);



    for (int i = len; i < len + n; i++)
    {
        char temp[20];
        do {
            cout << endl<<"Vuvedete nomer na uchastnika (cqlo chislo, po-golqmo ot 0): ";
            cin.getline(temp, 20);
            arr[i].number = atoi(temp);
        } while (arr[i].number <= 0);


        cout << "Vuvedete ime na uchastnika: ";
        cin.getline(arr[i].name, 50);

        do {
            cout << "Vuvedete vuzrast na uchastnika (cqlo chislo, po-golqmo ot 0): ";
            cin.getline(temp, 20);
            arr[i].age = atoi(temp);
        } while (arr[i].age <= 0);



        do {
            cout << "Izberete pol na uchastnika - \'M\' za muj i \'F\' za jena: ";
            cin >> arr[i].sex;
            cin.ignore();
        } while ((arr[i].sex != 'm' && arr[i].sex != 'M') && (arr[i].sex != 'f' && arr[i].sex != 'F'));


        do {
            cout << "Vuvedete bedrena obikolka na uchastnika (chislo, po-golqmo ot 0): ";
            cin.getline(temp, 20);
            arr[i].bedr_o = atof(temp);
        } while (arr[i].bedr_o <= 0);


        do {
            cout << "Vuvedete ramenna obikolka na uchastnika (chislo, po-golqmo ot 0): ";
            cin.getline(temp, 20);
            arr[i].ram_o = atof(temp);
        } while (arr[i].ram_o <= 0);


        do {
            cout << "Vuvedete obikolka na shiqta na uchastnika (chislo, po-golqmo ot 0): ";
            cin.getline(temp, 20);
            arr[i].shiq_o = atof(temp);
        } while (arr[i].shiq_o <= 0);


        do {
            cout << "Vuvedete obikolka na praseca na uchastnika (chislo, po-golqmo ot 0): ";
            cin.getline(temp, 20);
            arr[i].pras_o = atof(temp);
        } while (arr[i].pras_o <= 0);

    }
    len += n;
}
void output(member arr[], int len)
{
   
    for (int i = 0; i < len; i++)
    {
        cout << "Uchastnik nomer: " << arr[i].number;
        cout << endl << "Ime: " << arr[i].name;
        cout << endl << "Vuzrast: " << arr[i].age;
        if (arr[i].sex == 'm' || arr[i].sex == 'M')
            cout << endl << "Pol: Muj";
        if (arr[i].sex == 'f' || arr[i].sex == 'F')
            cout << endl << "Pol: Jena";
        cout << endl << "Bedrena obikolka: " << arr[i].bedr_o;
        cout << endl << "Ramenna obikolka: " << arr[i].ram_o;
        cout << endl << "Obikolka na shiqta: " << arr[i].shiq_o;
        cout << endl << "Obikolka na praseca: " << arr[i].pras_o << endl<<endl;
    }
    
}
void output_prop(member arr[], int len)
{

    for (int i = 0; i < len; i++)
    {

        cout << "Uchastnik nomer: " << arr[i].number;
        cout <<endl<< "Stoinost na proporcionalni telesni merki: " << formula(arr[i].bedr_o, arr[i].shiq_o, arr[i].pras_o, arr[i].ram_o);
        cout << endl << "Ime: " << arr[i].name;
        cout << endl << "Vuzrast: " << arr[i].age;
        if (arr[i].sex == 'm' || arr[i].sex == 'M')
            cout << endl << "Pol: Muj";
        if (arr[i].sex == 'f' || arr[i].sex == 'F')
            cout << endl << "Pol: Jena";
        cout << endl << "Bedrena obikolka: " << arr[i].bedr_o;
        cout << endl << "Ramenna obikolka: " << arr[i].ram_o;
        cout << endl << "Obikolka na shiqta: " << arr[i].shiq_o;
        cout << endl << "Obikolka na praseca: " << arr[i].pras_o << endl << endl;
    }

}
void minAge(member arr[], int len)
{
    int mini = arr[0].age;
    member temp_arr[maxBr];
    int brTemp = 0;

    for (int i = 0; i < len; i++)
        if (arr[i].age < mini)
            mini = arr[i].age;

    for (int i = 0; i < len; i++)
        if (arr[i].age == mini)
        {
            temp_arr[brTemp] = arr[i];
            brTemp++;
        }
    cout << "Uchastnicite s minimalna vuzrast " << mini << " sa:" << endl;
    output(temp_arr, brTemp);

}
void searchName(member arr[], int len)
{
    char searchItem[50];
    cout << "Vuvedete ime, po koeto da tursite uchastnik: ";
    cin.getline(searchItem, 50);
    int br = 0;

    for (int i = 0; i < len; i++)
    {
        if (_stricmp(arr[i].name, searchItem) == 0)
        {
            cout << endl << "Nameren uchastnik s ime " << searchItem << ": " << endl;

            cout << "Uchastnik nomer: " << arr[i].number;
            cout << endl << "Ime: " << arr[i].name;
            cout << endl << "Vuzrast: " << arr[i].age;
            if (arr[i].sex == 'm' || arr[i].sex == 'M')
                cout << endl << "Pol: Muj";
            if (arr[i].sex == 'f' || arr[i].sex == 'F')
                cout << endl << "Pol: Jena";
            cout << endl << "Bedrena obikolka: " << arr[i].bedr_o;
            cout << endl << "Ramenna obikolka: " << arr[i].ram_o;
            cout << endl << "Obikolka na shiqta: " << arr[i].shiq_o;
            cout << endl << "Obikolka na praseca: " << arr[i].pras_o << endl << endl;
            br++;
        }
    }
    if (br == 0)
        cout << endl << "Nqma nameren uchastnik s ime " << searchItem<<endl;
}
void sortAge(member arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - 1 - i; j++)
            if (arr[j].age > arr[j + 1].age)
            {
                member temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
void sortAgeName(member arr[], int len)
{
    member temp[maxBr];
    for (int i = 0; i < len; i++)
    {
        temp[i].number = arr[i].number;
        strcpy_s(temp[i].name, arr[i].name);
        temp[i].age = arr[i].age;
        temp[i].sex = arr[i].sex;
        temp[i].bedr_o = arr[i].bedr_o;
        temp[i].ram_o = arr[i].ram_o;
        temp[i].shiq_o = arr[i].shiq_o;
        temp[i].pras_o = arr[i].pras_o;
    }

    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (temp[j].age == temp[j + 1].age)
            {
                if (strcmp(temp[j].name, temp[j + 1].name) == 1)        //1>2
                {
                    member tempu = temp[j];
                    temp[j] = temp[j + 1];
                    temp[j + 1] = tempu;
                }
            }
            else if (temp[j].age > temp[j + 1].age)
            {
                member tempu = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = tempu;
            }
        } 
    cout << "Izvejdane na podredeniq masiv"<<endl;
    output(temp, len);
}
void searchAgeSex(member arr[], int len)
{
    char temp[20];
    double sAge;
    char sChar;
    member sArr[maxBr];
    int brA = 0;

    do {
        cout << endl << "Vuvedete stoinost za vuzrast po koqto da se tursqt i izvedat uchastnicite (stoinost po-golqma ot 0): ";
        cin.getline(temp, 20);
        sAge = atoi(temp);
    } while (sAge == 0 || sAge < 0 || sAge != (int)sAge);

    do {
        cout << "Vuvedete stoinost za pola na tursenite uchastnici (\'M\' za muje i \'F\' za jeni): ";
        cin >> sChar;
        cin.ignore();
    } while (!((sChar == 'M' || sChar == 'm') || (sChar == 'F' || sChar == 'f')));

    for (int i = 0; i < len; i++)
        if (arr[i].age == sAge && arr[i].sex == sChar)
        {
            sArr[brA] = arr[i];
            brA++;
        }

    if (sChar == 'm' || sChar == 'M')
        strcpy_s(temp, "Muj");
    else strcpy_s(temp, "Jena");

    if (brA == 0)
    {
        cout << "Nqma uchastnik " << temp << " na " << sAge << " godini";
        return;
    }
    else output(sArr, brA);
}

void zapis(member arr[], int len)
{
    fp.open(fname, ios::out | ios::binary);
    if (fp.fail()) { cout << "Greshka!"; return; }
    fp.write((char*)arr, len * sizeof(member));
    fp.close();
}
void chetene(member arr[], int &len)
{
    member masiv[maxBr];
    fp.open(fname, ios::in | ios::binary);
    if (fp.fail()) { cout << "Greshka!"; return; }

    fp.seekg(0L, ios::end);
    len = fp.tellg() / (int)sizeof(member);
    if (len == 0)
    {
        cout << "Nqma danni vuv faila!"<<endl;
    }
    else
    {
        fp.seekg(0L, ios::beg);
        fp.read((char*)arr, len * sizeof(member));
    }

    fp.close();
}

void podmenu(member arr[], int& len, member gr1[], member gr2[], member gr3[], member gr4[], int& len1, int& len2, int& len3, int& len4)
{


    int izbor;

    do {
        system("cls");
        cout << "Tova e podmenu s dopulnitelni funkcii kum programata.";
        cout << endl << "1. Izvejdane na uchastnicite v podreden red po godini i ime";
        cout << endl << "2. Tursene i izvejdane na uchastnicite po vuvedeni vuzrast i pol";
        cout << endl << "0. Izhod ot podmenuto";
        cout << endl;
        cin >> izbor;
        cin.ignore();

        switch (izbor)
        {
        case 1:
            cout << "Podrejdane i izvejdane..." << endl;
            sortAgeName(arr, len);
            break;
        case 2:

            cout << endl << "Tursene i izvejdane...";
            searchAgeSex(arr, len);
            break;
        case 0:
            menu(arr, len, gr1, gr2, gr3, gr4, len1, len2, len3, len4);
            break;
        default:

            cout << "Greshno vuveden izbor"<<endl;
            break;
        }
        cin.get();

    } while (izbor != 0);
}
void sortNizh(member arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
        for (int j = 0; j < length - 1 - i; j++)
            if (formula(arr[j].bedr_o, arr[j].shiq_o, arr[j].pras_o, arr[j].ram_o) < formula(arr[j + 1].bedr_o, arr[j + 1].shiq_o, arr[j + 1].pras_o, arr[j + 1].ram_o))
            {
                member temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
void sortVuzh(member arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
        for (int j = 0; j < length - 1 - i; j++)
            if (formula(arr[j].bedr_o, arr[j].shiq_o, arr[j].pras_o, arr[j].ram_o) > formula(arr[j + 1].bedr_o, arr[j + 1].shiq_o, arr[j + 1].pras_o, arr[j + 1].ram_o))
            {
                member temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
