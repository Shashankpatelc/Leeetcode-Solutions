class Solution {
    public double separateSquares(int[][] squares) {
        double totalArea = 0;
        int n = squares.length;
        
        double[][] events = new double[2 * n][3];
        
        for (int i = 0; i < n; i++) {
            double y = squares[i][1];
            double side = squares[i][2];
            
            totalArea += side * side;
            
            events[2 * i][0] = y;          
            events[2 * i][1] = 1;           
            events[2 * i][2] = side;        
            
            events[2 * i + 1][0] = y + side; 
            events[2 * i + 1][1] = -1;       
            events[2 * i + 1][2] = side;     
        }

        Arrays.sort(events, (a, b) -> Double.compare(a[0], b[0]));
        
        double target = totalArea / 2.0;
        double currentArea = 0;
        double currentWidth = 0;
        
        for (int i = 0; i < events.length - 1; i++) {
            double type = events[i][1];
            double width = events[i][2];
            
            if (type == 1) currentWidth += width; 
            else currentWidth -= width;           

            double y1 = events[i][0];
            double y2 = events[i+1][0];
            double h = y2 - y1;
            
            double stripArea = h * currentWidth;
            
            if (currentArea + stripArea >= target) {
                double missingArea = target - currentArea;
                return y1 + (missingArea / currentWidth);
            }
            
            currentArea += stripArea;
        }
        
        return events[events.length - 1][0];
    }
}