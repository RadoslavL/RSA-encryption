#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int gcd(int a, int b){
   int i;
   int out = -1;
   for(i = 1; i <= a && i <= b; i++){
      if(a % i == 0 && b % i == 0){
         out = i;
      }
   }
   return out;
}

unsigned long long power(int number, int power){
   int i;
   unsigned long long out = 1;
   for(i = 0; i < power; i++){
      out = out * number;
   }
   return out;
}

int lcm(int a, int b){
   int i;
   for(i = (a > b) ? a : b; (i % a != 0) || (i % b != 0); i++);
   return i;
}

int modularinverse(int a, int b){
   int i;
   for(i = 1; i < b; i++){
      if(((a % b) * (i % b)) % b == 1){
         break;
      }
   }
   return i;
}

int modularpow(int base, int exponent, int modulus){
   if(modulus == 1){
      return 0;
   }
   unsigned long long int c = 1;
   int i;
   for(i = 0; i < exponent; i++){
      c = (c * base) % modulus;
   }
   return c;
}

int encrypt(int n, int e, int msg){
   int c = modularpow(msg, e, n);
   return c;
}

int decrypt(int n, int c, int d){
   int m = modularpow(c, d, n);
   return m;
}

int pubkey(int p, int q){
   int n = p * q;
   return n;
}

int privatekey(int p, int q, int e){
   int d = modularinverse(e, lcm(p - 1, q - 1));
   return d;
}

int main(){
   int p = 1259; //10067; //907;
   int q = 1277; //10069; //773;
   int n = pubkey(p, q);
   int e = 13;
   unsigned long long msg;
   scanf("%lld", &msg);
   int c = encrypt(n, e, msg);
   int d = privatekey(p, q, e);
   int m = decrypt(n, c, d);
   FILE* file;
   file = fopen("resources", "w");
   fprintf(file, "%d\n", c);
   fclose(file);
   file = fopen("resources", "r");
   printf("%d\n", n);
   printf("%d\n", d);
   printf("%d\n", c);
   printf("%d\n", m);
   return 0;
}
