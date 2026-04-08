
int main() {
char a[100];
int d;
int* b = ( int* )&a;
*b = 1;
static char c[100];
b = ( int* )&c;
*b = 2;
//_Thread_local char d[100];
b = ( int* )&d;
*b = 3;
}