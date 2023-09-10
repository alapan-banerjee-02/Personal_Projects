import java.util.*;
class Cal{
	int sum(int a,int b){
		return a+b;
	}
	int sub(int a,int b){
		return a-b;
	}
	int mul(int a,int b){
		return a*b;
	}
	int div(int a,int b){
		return a/b;
	}
	int pow1(int a){
		return a*a;
	}
	int pow2(int a,int b){
		int c=1;
		for(int i=0;i<b;i++)
			c= c*a;
		return c;
	}
	double sinx(double a){
		return Math.sin(Math.toRadians(a));
	}
	double cosx(double a){
		return Math.cos(Math.toRadians(a));
	}
	double tanx(double a){
		return Math.tan(Math.toRadians(a));
	}
	double radian(double a){
		return Math.toRadians(a);
	}
	int fact(int a){
		int ans=1;
		if(a==0){
			return 1;
		}
		else{
			for(int i=a;i>0;i--){
				ans=ans*i;
			}
		}
		return ans;
	}
	int p(int n,int r){
		return fact(n)/fact(n-r);
	}
	int c(int n,int r){
		return fact(n)/(fact(n-r)*fact(r));
	}
	double log(double a){
		return Math.log(a);
	}
	double cosecx(double a){
		return 1/sinx(Math.toRadians(a));
	}
	double secx(double a){
		return 1/cosx(Math.toRadians(a));
	}
	double cotx(double a){
		return 1/tanx(Math.toRadians(a));
	}
}
class Calculator{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a=0,b=0;
		double d=0;
        Cal c=new Cal();
		while(true){
			System.out.println("Press 1 for summation");
			System.out.println("Press 2 for subtraction");
			System.out.println("Press 3 for multiplication");
			System.out.println("Press 4 for division");
			System.out.println("Press 5 for square");
			System.out.println("Press 6 for power");
			System.out.println("Press 7 for sin");
			System.out.println("Press 8 for cosin");
			System.out.println("Press 9 for tan");
			System.out.println("Press 10 for radian");
			System.out.println("Press 11 for factorial");
			System.out.println("Press 12 for permutation");
			System.out.println("Press 13 for combination");
			System.out.println("Press 14 for log");
			System.out.println("Press 15 for cosec");
			System.out.println("Press 16 for sec");
			System.out.println("Press 17 for cot");
			System.out.println("Press 18 to quit");
			System.out.println("Enter the choice:");
			int c1 = sc.nextInt();
			switch(c1){
			case 1:
				System.out.println("Enter the first num:");
				a = sc.nextInt();
				System.out.println("Enter the second num:");
				b = sc.nextInt();
				System.out.println("Sum of two elements is: "+c.sum(a,b));
				break;
			case 2:
				System.out.println("Enter the first num:");
				a = sc.nextInt();
				System.out.println("Enter the second num:");
				b = sc.nextInt();
				System.out.println("Sub of two elements is: "+c.sub(a,b));
				break;
			case 3:
				System.out.println("Enter the first num:");
				a = sc.nextInt();
				System.out.println("Enter the second num:");
				b = sc.nextInt();
				System.out.println("mul of two elements is: "+c.mul(a,b));
				break;
			case 4:
				System.out.println("Enter the first num:");
				a = sc.nextInt();
				System.out.println("Enter the second num:");
				b = sc.nextInt();
				System.out.println("div of two elements is: "+c.div(a,b));
				break;
			case 5:
				System.out.println("Enter the num:");
				a = sc.nextInt();
				System.out.println("Power of  elements is: "+c.pow1(a));
				break;
			case 6:
				System.out.println("Enter the first num:");
				a = sc.nextInt();
				System.out.println("Enter the second num:");
				b = sc.nextInt();
				System.out.println("Power of two elements is: "+c.pow2(a,b));
				break;	
			case 7:
				System.out.println("Enter the num:");
				d = sc.nextDouble();
				System.out.println("sin of  elements is: "+c.sinx(d));
				break;
			case 8:
				System.out.println("Enter the num:");
				d = sc.nextDouble();
				System.out.println("cos of  elements is: "+c.cosx(d));
				break;
			case 9:
				System.out.println("Enter the num:");
				d = sc.nextDouble();
				System.out.println("tan of  elements is: "+c.tanx(d));
				break;
			case 10:
				System.out.println("Enter the num:");
				d = sc.nextDouble();
				System.out.println("radian of  elements is: "+c.radian(d));
				break;
			case 11:
				System.out.println("Enter the num:");
				a = sc.nextInt();
				System.out.println("fact of  elements is: "+c.fact(a));
				break;
			case 12:
				System.out.println("Enter the first num:");
				a = sc.nextInt();
				System.out.println("Enter the second num:");
				b = sc.nextInt();
				System.out.println("par.. of two elements is: "+c.p(a,b));
				break;
			case 13:
				System.out.println("Enter the first num:");
				a = sc.nextInt();
				System.out.println("Enter the second num:");
				b = sc.nextInt();
				System.out.println("Combination: "+c.c(a,b));
				break;
			case 14:
				System.out.println("Enter the first num:");
				d = sc.nextDouble();
				System.out.println("Log: "+c.log(d));
				break;
			case 15:
				System.out.println("Enter the num:");
				d = sc.nextDouble();
				System.out.println("Cosec: "+c.cosecx(d));
				break;
			case 16:
				System.out.println("Enter the num:");
				d = sc.nextDouble();
				System.out.println("sec: "+c.secx(d));
				break;
			case 17:
				System.out.println("Enter the num:");
				d = sc.nextDouble();
				System.out.println("Cot: "+c.cotx(d));
				break;
			case 18:
				System.exit(0);
			default:
				System.out.println("Wrong choice");
				break;
			}
		}
	}
	
}