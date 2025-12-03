#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i=0;i<n-1;i++) {
        int m=i;
        for (int j=i+1;j<n;j++)
            if (a[j]<a[m]) m=j;
        swap(a[i],a[m]);
    }
}

void insertionSort(int a[], int n) {
    for (int i=1;i<n;i++) {
        int x=a[i], j=i-1;
        while (j>=0 && a[j]>x) { a[j+1]=a[j]; j--; }
        a[j+1]=x;
    }
}

void bubbleSort(int a[], int n) {
    for (int i=0;i<n-1;i++)
        for (int j=0;j<n-i-1;j++)
            if (a[j]>a[j+1]) swap(a[j],a[j+1]);
}

void mergeArr(int a[], int l, int m, int r) {
    int i=l, j=m+1, k=0;
    int b[r-l+1];
    while (i<=m && j<=r) b[k++] = a[i] < a[j] ? a[i++] : a[j++];
    while (i<=m) b[k++] = a[i++];
    while (j<=r) b[k++] = a[j++];
    for (i=l, j=0; i<=r; i++, j++) a[i] = b[j];
}
void mergeSort(int a[], int l, int r) {
    if (l<r) {
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        mergeArr(a,l,m,r);
    }
}

int partitionArr(int a[], int l, int r) {
    int p=a[r], i=l-1;
    for (int j=l;j<r;j++)
        if (a[j]<p) swap(a[++i],a[j]);
    swap(a[i+1],a[r]);
    return i+1;
}
void quickSort(int a[], int l, int r) {
    if (l<r) {
        int pi = partitionArr(a,l,r);
        quickSort(a,l,pi-1);
        quickSort(a,pi+1,r);
    }
}

int main() {
    int n; cin >> n;
    int a[n], b[n];
    for (int i=0;i<n;i++) cin >> a[i];
    int ch;
    cin >> ch;
    for (int i=0;i<n;i++) b[i] = a[i];
    if (ch == 1) selectionSort(b,n);
    else if (ch == 2) insertionSort(b,n);
    else if (ch == 3) bubbleSort(b,n);
    else if (ch == 4) mergeSort(b,0,n-1);
    else if (ch == 5) quickSort(b,0,n-1);
    for (int i=0;i<n;i++) cout << b[i] << " ";
}
