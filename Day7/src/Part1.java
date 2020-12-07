import java.io.*;
import java.util.HashMap;

public class Part1 {
    static HashMap<String,HashMap<String, Integer>> hashMap = new HashMap<String,HashMap<String, Integer>>();
    static int whole = 0;
    static HashMap<String, Integer> buffer = new HashMap<String, Integer>();

    public static int findHash(String key){
        int res = 0;
        for (String k : hashMap.keySet()) {
            HashMap<String, Integer> subHash = hashMap.get(k);
            for(String i : subHash.keySet()){
//                System.out.println("subHash: "+subHash.get(i) + "\n");
                if(i.equals(key)){
                    System.out.println( i + " - " + k);
                    if(!buffer.containsKey(k)){
                        whole++;
                        buffer.put(k, whole);
                        res = res + 1 + findHash(k);
                    }
                }
            }
        }
        return res;
    }

    public static void main(String arg[]) throws IOException {
        File input = new File("input_copy.txt");
        InputStreamReader i = new InputStreamReader(new FileInputStream(input));
        BufferedReader reader = new BufferedReader(i);
        String temp = null;
        String header = null;
        String sub = null;
        int num = 0;
        HashMap<String, Integer> subHash = new HashMap<String, Integer>();
        int count = 0;
        while((temp = reader.readLine())!=null){
//            System.out.println(temp+"\n");
            if(temp.contains("*")){
                if(!hashMap.containsKey(header)){
                    //put上一次的
//                    for(Integer fuck : subHash.keySet()){
//                        System.out.println("fuck: " + subHash.get(fuck));
//                    }
//                    System.out.println("header: " + header + "\n");
                    HashMap<String, Integer> copy = (HashMap<String, Integer>) subHash.clone();
                    hashMap.put(header, copy);
//                    System.out.println(hashMap.get(header) + "\n");
                    subHash.clear();
                }
                //Header
                header = reader.readLine();
//            System.out.println(header+"\n");
            }
            if(temp.contains("1") || temp.contains("2") || temp.contains("3") || temp.contains("4") || temp.contains("5")){
                num = Integer.parseInt(temp);
//                System.out.println(num+"\n");
                sub = reader.readLine();
//                System.out.println("sub: " + sub+"\n");
                if(!subHash.containsKey(sub)){
//                    System.out.println("shit!\n");
                    subHash.put(sub, num);
                }
            }
        }


//        System.out.println("Get: " + hashMap.get("dullpurple"));
        int res = findHash("shinygold");
        System.out.println("PART I: " + res + "\n");

    }
}
