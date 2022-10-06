class LRUCache {
    LinkedHashMap <Integer,Integer> map;
    int cap;
    public LRUCache(int capacity) {
        this.cap = capacity;
        map = new LinkedHashMap<>();
    }
    
    public int get(int key) {
        if(!map.containsKey(key)){
            return -1;
        }
        makeRecent(key);
        return map.get(key);
    }
    
    public void put(int key, int value) {
        if(map.containsKey(key)){
            map.remove(key);
        }
        while(map.size() >= this.cap){
            map.remove(map.keySet().iterator().next());
        }
        map.put(key,value);
    }
    
    public void makeRecent(int key){
        int val = map.get(key);
        map.remove(key);
        map.put(key,val);
    }
}
