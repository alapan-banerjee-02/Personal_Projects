import java.util.*;
import java.lang.Math;
class c{
    static int gcd(int dr,int dv){
        int temp=0;
        for(int i=dr;i>0;i--){
            if((dr%i==0)&&(dv%i==0)){
                temp=i;
                break;
            }
            //System.out.println("G.C.D of two numbers:"+i);
        }
        lcm(dr,dv,temp);
        return temp;
    }
    static void lcm(int n1,int n2,int gval){
        int t= Math.abs(n1*n2)/gval;
        System.out.println("L.C.M of two numbers:"+t);
    }
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the first number:");
        int a= sc.nextInt();
        System.out.println("Enter the second number:");
        int b= sc.nextInt();
        //gcd(a,b);
        System.out.println("G.C.D of two numbers:"+gcd(a,b));
    }
}