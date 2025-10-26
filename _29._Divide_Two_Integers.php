class Solution {

    /**
     * @param Integer $dividend
     * @param Integer $divisor
     * @return Integer
     */
    function divide($dividend, $divisor) {
        if ($dividend < -2147483647 && $divisor < 0 && $dividend != $divisor){
            $dividend = -2147483647;
            return (int)($dividend/$divisor);
        }
        return (int)($dividend/$divisor);
    }
}
