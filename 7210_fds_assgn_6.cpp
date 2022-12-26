// Name = Anupam
// Roll No = 7210
// SE COMP-B

#include <bits/stdc++.h>
using namespace std;

void evaluate_1D(int poly[], int x, int n)
{
    int value = 0;
    for (int i = 0; i < n + 1; i++)
    {
        value += (poly[i] * pow(x, i));
    }
    cout << "The value of the polynomial for x = " << x << " by representation of 1D array is : " << value << endl;
}

void add2D(int arr1[][2], int arr2[][2], int term1, int term2)
{
    int add[term1 + term2][2];
    int count1 = 0;
    for (int i = 0; i < term1; i++)
    {
        bool flag = true;
        for (int j = 0; j < term2; j++)
        {
            if (arr1[i][1] == arr2[j][1])
            {
                flag = false;
                add[count1][1] = arr1[i][1];
                add[count1][0] = arr1[i][1] + arr2[j][1];
            }
        }
        if (flag)
        {
            add[count1][1] = arr1[i][1];
            add[count1][0] = arr1[i][1];
        }
        count1++;
    }
    for (int i = 0; i < term2; i++)
    {
        bool flag = true;
        for (int j = 0; j < term1; j++)
        {
            if (arr2[i][1] == arr1[j][1])
            {
                flag = false;
            }
        }
        if (flag)
        {
            add[count1][1] = arr2[i][1];
            add[count1][0] = arr2[i][0];
            count1++;
        }
    }
}


void multiply_2D(int arr1[][2], int arr2[][2], int term1, int term2)
{
    int multi[term1 * term2][2] = {{0, 0}};
    int count1 = 0;
    for (int i = 0; i < term1; i++)
    {
        for (int j = 0; j < term2; j++)
        {
            multi[count1][0] = arr1[i][0] * arr2[j][0];
            multi[count1][1] = arr1[i][1] + arr2[j][1];
        }
    }
    for (int i = 0; i < term1 * term2; i++)
    {
        cout << multi[i][0] << " " << multi[i][1] << endl;
    }
}


void print_poly(int poly[], int degree)
{
    for (int i = degree; i >= 0; i--)
    {
        if (i != 0 and poly[i] != 0)
        {
            cout << poly[i] << "x^" << i << " + ";
        }
        else if (poly[i] != 0)
        {
            cout << poly[i] << "x^" << i << endl;
        }
    }
}

void add_1D(int poly1[], int poly2[], int degree1, int degree2)
{
    int size = max(degree1, degree2);
    int small = min(degree1, degree2);
    int add[size + 1] = {0};
    for (int i = 0; i < size + 1; i++)
    {
        if (degree1 < degree2)
        {
            if (i <= small)
            {
                add[i] = poly1[i] + poly2[i];
            }
            else
            {
                add[i] = poly2[i];
            }
        }
        else
        {
            if (i <= small)
            {
                add[i] = poly1[i] + poly2[i];
            }
            else
            {
                add[i] = poly1[i];
            }
        }
    }
    print_poly(add, size);
}

void multiply_1D(int poly1[], int poly2[], int degree1, int degree2)
{
    int length = degree1 + degree2;
    int multi[length + 1] = {0};
    for (int i = 0; i < degree1 + 1; i++)
    {
        for (int j = 0; j < degree2 + 1; j++)
        {
            multi[i + j] += (poly1[i] * poly2[j]);
        }
    }
    print_poly(multi, length);
}

void print_2D(int arr[][2], int term)
{
    for (int i = 0; i < term; i++)
    {
        if (i != term - 1)
            cout << arr[i][0] << "x^" << arr[i][1] << " + ";
        else
            cout << arr[i][0] << "x^" << arr[i][1] << endl;
    }
}
void evaluate2D(int arr[][2], int terms, int x)
{
    int value = 0;
    for (int i = 0; i < terms; i++)
    {
        value += arr[i][0] * (pow(x, arr[i][1]));
    }
    cout << " The value of the polynomial for x = " << x << " by representation of 2D array is : " << value << endl;
}




int main()
{
    int degree;
    cout << "Enter the degree of the first polynomial : " << endl;
    cin >> degree;
    int poly[degree + 1] = {0};
    int terms;
    cout << "Enter the number of the terms : " << endl;
    cin >> terms;
    int poly2D[terms][2];
    cout << "Enter the coefficients and exponents in the increasing form( space seperated) : ";
    for (int i = 0; i < terms; i++)
    {
        int coef;
        int exp;
        cin >> coef >> exp;
        poly[exp] = coef;
        poly2D[i][0] = coef;
        poly2D[i][1] = exp;
    }

    int degree2;
    cout << "Enter the degree of the second polynomial : " << endl;
    cin >> degree2;
    int poly2[degree2 + 1] = {0};
    int terms2;
    cout << "Enter the number of the terms : " << endl;
    cin >> terms2;
    cout << "Enter the coefficients and exponent of the second polynomial ( space seperated) : ";
    for (int i = 0; i < terms2; i++)
    {
        int coef;
        int exp;
        cin >> coef >> exp;
        poly2[exp] = coef;
    }

    cout << "Enter the value of x for which the first polynomial is to be evaluated : ";
    int x;
    cin >> x;
    evaluate_1D(poly, x, degree);
    add_1D(poly2, poly, degree2, degree);
    multiply_1D(poly2, poly, degree2, degree);
}