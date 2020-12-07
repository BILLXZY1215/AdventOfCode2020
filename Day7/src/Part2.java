import java.io.*;
import java.util.HashMap;

public class Part2 {
    static HashMap<String, HashMap<String, Integer>> hashMap = new HashMap<String,HashMap<String, Integer>>();
    static int whole = 0;

    public static int HashFind(String key){
        int res = 1;
        HashMap<String, Integer> buffer = hashMap.get(key);
        System.out.println(key + ": " + buffer);
        for(String k : buffer.keySet()){
            res = res + buffer.get(k)*HashFind(k);
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


//        System.out.println("Get: " + hashMap.get("shinygold"));
        int res = HashFind("shinygold");
        System.out.println("PART II: " + (res-1) + "\n");
    }
}
