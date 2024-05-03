class Solution {
    public int compareVersion(String version1, String version2) {
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        
        int i, n = (v1.length<v2.length) ? v1.length : v2.length;
        
        for(i=0; i<n; i++) {
            int x=Integer.parseInt(v1[i]);
            int y=Integer.parseInt(v2[i]);
            if(x<y)
                return -1;
            else if(x>y)
                return 1;
        }
        
        while(i<v1.length){
            if(Integer.parseInt(v1[i++])!=0)
                return 1;
        }
        
        while(i<v2.length){
            if(Integer.parseInt(v2[i++])!=0)
                return -1;
        }
        
        return 0;
    }
}