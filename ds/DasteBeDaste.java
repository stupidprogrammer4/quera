import java.util.Scanner;
public class DasteBeDaste {
    // res[1] maximum from l to r res[0] is prizes maximum
    private static long[] choose(int[] arr, int begin, int end) {
        if (end == begin) {
            long[] res = new long[2];
            res[0] = res[1] = arr[begin];
            return res;
        }
        int mid = (begin + end)/2;
        long[] X, Y;
        long[] res = new long[2];
        X = choose(arr, mid+1, end);
        Y = choose(arr, begin, mid);
        res[1] = Math.max(X[1], Y[1]);
        res[0] = Math.max(X[0] + Y[1], Y[0] + X[1]);
        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[1<<n];
        for (int i = 0; i < 1<<n; i++)
            arr[i] = sc.nextInt();
        System.out.println(choose(arr, 0, arr.length-1)[0]);
        sc.close();
    }
}
