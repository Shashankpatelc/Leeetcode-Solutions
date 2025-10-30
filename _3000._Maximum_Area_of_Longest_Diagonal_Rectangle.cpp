class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
      double max_dia = 0;
        int max_area = 0;

        for (const auto& dim : dimensions) {
            double dia = sqrt(dim[0] * dim[0] + dim[1] * dim[1]);
            int area = dim[0] * dim[1];

            if (dia == max_dia) {
                max_area = max(area, max_area);
            } else if (dia > max_dia) {
                max_dia = dia;
                max_area = area;
            }
        }

        return max_area;  
    }
};