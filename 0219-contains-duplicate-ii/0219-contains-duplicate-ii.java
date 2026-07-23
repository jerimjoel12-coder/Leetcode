class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer,Integer>  hp = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(hp.containsKey(nums[i]) && i-(hp.get(nums[i]))<=k){
                return true;
            }
            hp.put(nums[i],i);
      
        }
        return false;
    }
}