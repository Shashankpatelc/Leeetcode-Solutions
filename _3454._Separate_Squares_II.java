import java.util.*;

class Solution {
    public double separateSquares(int[][] squares) {

        Set<Integer> xSet = new HashSet<>();
        List<List<Integer>> events = new ArrayList<>();

        for (int[] sq : squares) {
            int x = sq[0];
            int y = sq[1];
            int l = sq[2];
            xSet.add(x);
            xSet.add(x + l);

            events.add(Arrays.asList(y, 1, x, x + l));
            events.add(Arrays.asList(y + l, -1, x, x + l));
        }

        List<Integer> uniqueX = new ArrayList<>(xSet);
        Collections.sort(uniqueX);
        
        Map<Integer, Integer> xToIndex = new HashMap<>();
        for (int i = 0; i < uniqueX.size(); i++) {
            xToIndex.put(uniqueX.get(i), i);
        }

        events.sort((a, b) -> Integer.compare(a.get(0), b.get(0)));

        SegmentTree st = new SegmentTree(uniqueX);
        long totalArea = 0;
        int prevY = events.get(0).get(0);

        for (List<Integer> event : events) {
            int currY = event.get(0);
            int type = event.get(1);
            int x1 = event.get(2);
            int x2 = event.get(3);

            long height = currY - prevY;
            long activeWidth = st.query(); 
            totalArea += activeWidth * height;


            st.update(xToIndex.get(x1), xToIndex.get(x2), type);
            prevY = currY;
        }

        double targetArea = totalArea / 2.0;
        double currentArea = 0;
        prevY = events.get(0).get(0);

        for (List<Integer> event : events) {
            int currY = event.get(0);
            int type = event.get(1);
            int x1 = event.get(2);
            int x2 = event.get(3);

            long height = currY - prevY;
            long activeWidth = st.query();
            
            if (currentArea + (double)activeWidth * height >= targetArea) {

                double missingArea = targetArea - currentArea;
                return prevY + (missingArea / activeWidth);
            }

            currentArea += (double)activeWidth * height;
            st.update(xToIndex.get(x1), xToIndex.get(x2), type);
            prevY = currY;
        }

        return prevY; 
    }

    static class SegmentTree {
        int n;
        int[] count;     
        long[] length;   
        List<Integer> X; 

        public SegmentTree(List<Integer> X) {
            this.X = X;
            this.n = X.size();
            this.count = new int[4 * n];
            this.length = new long[4 * n];
        }

        public void update(int x1_idx, int x2_idx, int val) {
            update(1, 0, n - 1, x1_idx, x2_idx - 1, val);
        }

        private void update(int node, int start, int end, int L, int R, int val) {
            if (L > end || R < start) return;

            if (L <= start && end <= R) {
                count[node] += val;
            } else {
                int mid = (start + end) / 2;
                update(2 * node, start, mid, L, R, val);
                update(2 * node + 1, mid + 1, end, L, R, val);
            }
            pushUp(node, start, end);
        }

        private void pushUp(int node, int start, int end) {
            if (count[node] > 0) {
                length[node] = (long) X.get(end + 1) - X.get(start);
            } else if (start != end) {
                length[node] = length[2 * node] + length[2 * node + 1];
            } else {
                length[node] = 0;
            }
        }

        public long query() {
            return length[1];
        }
    }
}