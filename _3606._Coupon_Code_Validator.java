class Coupon {
    String code;
    String businessLine;
    
    public Coupon(String code, String businessLine) {
        this.code = code;
        this.businessLine = businessLine;
    }
    
    public String getCode() {
        return code;
    }
    
    public String getBusinessLine() {
        return businessLine;
    }
}

class Solution {

    private boolean iscode(String s) {
        if ( s == null || s.isEmpty() )
            return false;
        
        for ( int i = 0 ; i < s.length() ; i++ ) {
            char ch = s.charAt(i);

            if( !( Character.isLetterOrDigit(ch) || ch == '_') ) {
                return false;
            }
        }

        return true;
    }

    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
        List<String> validCodes = new ArrayList<>();
        Map<String, Integer> priorityMap = new HashMap<>();
        priorityMap.put("electronics", 1);
        priorityMap.put("grocery", 2);
        priorityMap.put("pharmacy", 3);
        priorityMap.put("restaurant", 4);
        List<Coupon> validcoupons = new ArrayList<>();
    
        for ( int i = 0; i < code.length; i++ ) {

            boolean rule3 = isActive[i];
            if ( !rule3 ){
                continue;
            }
            String c = code[i];
            String business = businessLine[i];
    
            boolean rule1 = iscode(c);
            boolean rule2 = business.equals("electronics") || business.equals("grocery") || business.equals("pharmacy") || business.equals("restaurant"); 

            if( rule1 && rule2 && rule3 ) {
                Coupon valid = new Coupon(c,business);
                validcoupons.add(valid);
            }
        }

        validcoupons.sort(new Comparator<Coupon>() {
        @Override

            public int compare(Coupon c1, Coupon c2) {

                int p1 = priorityMap.get(c1.getBusinessLine());
                int p2 = priorityMap.get(c2.getBusinessLine());

                if (p1 != p2) {
                    return p1 - p2; 
                }

                return c1.getCode().compareTo(c2.getCode());
            }
        });

        for (Coupon coupon : validcoupons) {
           validCodes.add(coupon.getCode());
        }
        return validCodes;
    }
}