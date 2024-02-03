#include<stdio.h>
#include<windows.h>


void putcur(int r, int c){
   
    COORD CRD;
    CRD.X=r;
    CRD.Y=c;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}


int main(){


    int cmp, PMMR, CMMR;
    float w_fee, Fr_tax, PCA, PWA, gross;
    char con_NAME[40], con_ADD[40], typ[30], size[30], size1[10], acc_CDE[30];


    putcur(20, 2);
    printf("MCWD Water Bill Simulator");
    putcur(5, 4);
    printf("Consumer Name: ");
    putcur(5, 5);
    printf("Consumer Address: ");
    putcur(5, 6);
    printf("Account Code: ");
    putcur(5, 7);
    printf("Type: ");
    putcur(5, 8);
    printf("Size of Connection: ");
    putcur(5, 10);
    printf("Previous Month Meter Reading: ");
    putcur(45, 10);
    printf("Consumption");
    putcur(5, 11);
    printf("Current Month Meter Reading: ");
    putcur(30, 13);
    printf("Charges");
    putcur(50, 13);
    printf("Amount");
    putcur(30, 14);
    printf("WATER FEE");
    putcur(30, 15);
    printf("FRNCHSE TAX");
    putcur(30, 16);
    printf("PCA");
    putcur(30, 17);
    printf("PWA");
    putcur(30, 20);
    printf("Gross Current Bill");
   
    putcur(25, 4);
    fgets(con_NAME, sizeof(con_NAME), stdin);
    putcur(25, 5);
    fgets(con_ADD, sizeof(con_ADD), stdin);
    putcur(25, 6);
    fgets(acc_CDE, sizeof(acc_CDE), stdin);
    putcur(25, 7);
    fgets(typ, sizeof(typ), stdin);
    putcur(25, 8);
    fgets(size, sizeof(size), stdin);
    putcur(34, 10);
    scanf(" %d", &PMMR);
    putcur(34, 11);
    scanf(" %d", &CMMR);


    cmp = PMMR - CMMR;
    if (cmp < 0)
        cmp *= -1;
    putcur(45, 11);
    printf("%d", cmp);
    if (cmp > 10){
        cmp -= 10;
        if (cmp < 10)
            w_fee += cmp * 16.80;
        else
            w_fee += 10 * 16.80;}
    if (cmp > 10){
        cmp -= 10;
        if (cmp < 10)
            w_fee += cmp * 19.77;
        else
            w_fee += 10 * 19.77;}
    if (cmp > 10)
        w_fee += (cmp - 10) * 48.40;
    switch (size[0])
    {
        case '1':
                 switch (size[2])
                 {
                     case '2': w_fee += 152.00;
                         break;
                    case '1': w_fee += 1216.00;
                        break;
                     default:  
                             if (size[1]=='0')
                                 w_fee += 41952.00;                    
                             else
                                 w_fee += 486.00;
                        break;
                }                
            break;
        case '2':w_fee += 3040.00;
            break;
        case '3':
                 switch (size[2])
                 {
                 case '8': w_fee += 152.00;
                     break;
                 case '4': w_fee += 243.00;
                     break;
                 default:  w_fee += 5472.00;
                     break;
                 }
            break;
        case '4':w_fee += 10944.00;
            break;
        case '6':w_fee += 18240.00;
            break;
        case '8':w_fee += 29184.00;
            break;
        default: printf("\n\n\tERROR invalid Size of connection");
            break;
    }
    Fr_tax = w_fee * 0.02;
    PCA = w_fee * 0.40;
    PWA = w_fee * 0.10;
    gross = w_fee + Fr_tax + PCA + PWA;
    putcur(50, 14);
    printf("%.2f", w_fee);
    putcur(50, 15);
    printf("%.2f", Fr_tax);
    putcur(50, 16);
    printf("%.2f", PCA);
    putcur(50, 17);
    printf("%.2f", PWA);
    putcur(50, 20);
    printf("%.2f", gross);


return 0;  
}
