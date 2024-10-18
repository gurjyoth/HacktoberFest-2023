import java.util.Arrays;
import java.util.Scanner;

public class ArrayMinMax {
    static void getMinMax(long a[], long n) {
        long maxNo = Long.MIN_VALUE; // Use Long.MIN_VALUE for long type
        long minNo = Long.MAX_VALUE; // Use Long.MAX_VALUE for long type
        
        for (int i = 0; i < n; i++) {
            if (a[i] > maxNo) {
                maxNo = a[i];
            }
            if (a[i] < minNo) {
                minNo = a[i];
            }
        }
        
        System.out.println("min = " + minNo);
        System.out.println("max = " + maxNo);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long a[] = new long[n];
        
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong(); // Use nextLong() for long input
        }
        
        getMinMax(a, n);
        
        // Check if there are at least 4 elements before accessing a[3]
        if (n >= 4) {
            Arrays.sort(a);
            System.out.println("Fourth smallest element = " + a[3]);
        } else {
            System.out.println("Array does not have enough elements to access the fourth smallest element.");
        }
        
        sc.close(); // Close the scanner
    }
}
