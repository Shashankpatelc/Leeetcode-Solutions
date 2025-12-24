import java.util.*;

class Solution {
    public static void reverse(int[] a)
    {
        int n = a.length;

        for (int i = 0; i < n / 2; i++) {

            int t = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = t;

        }
    }

    public int minimumBoxes(int[] apple, int[] capacity) {
        int total_apple = 0, count = 0;
        
        for ( int i = 0; i < apple.length; i++ ) {
            total_apple += apple[i];
        }

        Arrays.sort(capacity);
        reverse(capacity);

        for ( int i = 0; i < capacity.length; i++ ) {
            if ( capacity[i] >= total_apple ) {
                count++;
                break;
            }
            total_apple -= capacity[i];
            count++;
        }

        return count;
    }
}