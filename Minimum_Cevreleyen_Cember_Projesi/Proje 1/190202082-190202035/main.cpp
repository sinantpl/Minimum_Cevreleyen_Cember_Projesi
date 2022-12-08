#include <stdio.h>
#include <graphics.h>
#include<math.h>

 int fct(int n){

if(n==0)// n elemanli bir islem icin n kez sorgu yapar.
    return 1;//rekursifligin bittigi durumda calisan son cagri oldugu icin tek bir kez calisir ve islem biter : 1
else
    return n*fct(n-1);// n-1 kez çalýþýr
    //Bu fonksiyon toplam zaman karmasikligi= n+1+n-1= 2n'dir.
}

int cmb(int n,int r){

return (fct(n)/(fct(n-r)*fct(r)));//Zaman Karmasikligi= 1'dir.
}

 main(){

    int noktalar[100][2];//Zaman Karmasikligi= 1'dir.
    int n=0;//Zaman Karmasikligi= 1'dir.
    float enbuyuk,d,g,enbuyuk2;//Zaman Karmasikligi= 1'dir.
    int a,b,c,e;//Zaman Karmasikligi= 1'dir.
    d=0;//Zaman Karmasikligi= 1'dir.
    g=0;//Zaman Karmasikligi= 1'dir.
    enbuyuk=d;//Zaman Karmasikligi= 1'dir.
    enbuyuk2=g;//Zaman Karmasikligi= 1'dir.
    FILE *fp=fopen("proje.txt","r");
    while(!feof(fp))
    {
        char satir[50];
        if(fgets(satir,50,fp)==NULL)
            break;
        sscanf(satir,"%d %d",&noktalar[n][0],&noktalar[n][1]);
        n++;
        //zaman karmasikligi= n'dir.
    }
    fclose(fp);
    printf("Girdiginiz Noktalar:\n");//Zaman Karmasikligi= 1'dir.
    for(int i=0; i<n; i++)
    {
        printf("{%d,%d}\n",noktalar[i][0],noktalar[i][1]);
        //Zaman Karmasikligi= n'dir.
    }
    printf("\n");//Zaman Karmasikligi= 1'dir.
    for(int m=0;m<n;m++)
    {
        for(int z=0;z<n;z++)
         {
            int d1=pow((noktalar[m][0]-noktalar[z+1][0]),2);

            int d2=pow((noktalar[m][1]-noktalar[z+1][1]),2);

            d=sqrt(d1+d2);
            if(d>enbuyuk)
            {
                enbuyuk=d;
                a=noktalar[m][0];
                b=noktalar[m][1];
                c=noktalar[z+1][0];
                e=noktalar[z+1][1];
            }


        }
        //Zaman Karmasikligi= n²'dir.
  }

float merkez1=(a+c)/2.0;//Zaman Karmasikligi= 1'dir.
float merkez2=(b+e)/2.0;//Zaman Karmasikligi= 1'dir.
printf("Merkez:(%0.2f,%0.2f)\n",merkez1,merkez2);//Zaman Karmasikligi= 1'dir.
for(int a=0;a<n;a++)
         {
            float d3=pow((merkez1-noktalar[a][0]),2);

            float d4=pow((merkez2-noktalar[a][1]),2);

            g=sqrt(d3+d4);
            if(g>enbuyuk2)
            {
                enbuyuk2=g;

            }
            //Zaman Karmasikligi= n'dir.
         }
float yaricap=enbuyuk2;//Zaman Karmasikligi= 1'dir.
printf("Yaricap:%0.4f\n",yaricap);//Zaman Karmasikligi= 1'dir.
printf("\nYukaridaki daire %0.4f yaricapli ve merkez (%0.2f,%0.2f) ile cizildiginde ",yaricap,merkez1,merkez2);//Zaman Karmasikligi= 1'dir.
printf("belirtilen tum noktalarin dairenin icinde veya uzerinde oldugu gorulmektedir.\n");//Zaman Karmasikligi= 1'dir.

int sur=DETECT,gmode;
          initgraph(&sur,&gmode,"");//Zaman Karmasikligi= 1'dir.
          setcolor(RED);//Zaman Karmasikligi= 1'dir.
          line(0,240,10000,240);//Zaman Karmasikligi= 1'dir.
          setcolor(RED);//Zaman Karmasikligi= 1'dir.
          line(300,0,300,1000);//Zaman Karmasikligi= 1'dir.
          for(int i=0;i<70;i++)
          {
              setcolor(WHITE);
              circle(20*i,240,2);
              //Zaman Karmasikligi= 70'tir.
          }
          for(int j=0;j<70;j++)
          {
              setcolor(WHITE);
              circle(300,20*j,2);
              //Zaman Karmasikligi= 70'tir.
          }

          for(int i=0; i<n; i++)
          {

        int k=noktalar[i][0]; int l=noktalar[i][1];
        setcolor(GREEN);
        circle(300+(20*k),240-(20*l),4);
        //Zaman Karmasikligi= n'dir.
          }

          float t,x,y,ax[50],ay[50];//Zaman Karmasikligi= 1'dir.
          int h;//Zaman Karmasikligi= 1'dir.
          h=n-1;//Zaman Karmasikligi= 1'dir.
 for( t=0;t<=1;t=t+0.0001){

         x=0;  y=0;

        for(int i=0;i<=h;i++)
        {
ax[i]=noktalar[i][0]; ay[i]=noktalar[i][1];
           x=x+(cmb(h,i)*pow(1-t,h-i)*pow(t,i)*ax[i]);
           y=y+(cmb(h,i)*pow(1-t,h-i)*pow(t,i)*ay[i]);
           //Zaman Karmasikligi= n-1'dir.
        }
            putpixel(300+x*20,240-y*20,5);
           //Zaman Karmasikligi= 2*10.000*(n-1)=20.000*(n-1)'dir.
 }
          setcolor(12);//Zaman Karmasikligi= 1'dir.
          circle(300+(20*merkez1),240-(20*merkez2),yaricap*20);//Zaman Karmasikligi= 1'dir.
          setcolor(BLUE);//Zaman Karmasikligi= 1'dir.
          line(300+merkez1*20,240-merkez2*20,300+(merkez1+yaricap)*20,240-merkez2*20);//Zaman Karmasikligi= 1'dir.
          setcolor(YELLOW);//Zaman Karmasikligi= 1'dir.
          circle(300+(20*merkez1),240-(20*merkez2),3);//Zaman Karmasikligi= 1'dir.
          getchar();//Zaman Karmasikligi= 1'dir.
          closegraph();//Zaman Karmasikligi= 1'dir.
 return 0;
          /*Zaman Karmasikligi= n²+20.006n-19826
          BigO Notasyonu O(n²) olarak bulunur.*/

 }
