
import java.util.*;

public class foodprocessor {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int s = in.nextInt(); // starting average piece size
        int t = in.nextInt(); // target piece size
        int n = in.nextInt(); // n is number of blades

        List<Blade> blades = new ArrayList<>();
        for(int i = 0; i < n; i++){
            blades.add(new Blade(in.nextInt(), in.nextInt()));
        }
        Collections.sort(blades, (a,b) -> b.max_size-a.max_size); // sort from the largest max size blade to smallest

        PriorityQueue<State> pq = new PriorityQueue<>( (a,b) -> Double.compare(a.time, b.time));

        pq.add(new State(s, 0)); // start the state at starting piece size and time 0

        Map<Double, Double> visited = new HashMap<>();

        while(!pq.isEmpty()) {
            State current_state = pq.poll();

            // Base case: reached target
            if(current_state.size <= t) {
                System.out.print(current_state.time);
                return;
            }

            // Skip already visited
            if(visited.containsKey(current_state.size) && visited.get(current_state.size) <= current_state.time) {
                continue;
            }
            visited.put(current_state.size, current_state.time);

            for(int i = 0; i < blades.size(); i++) {
                Blade blade = blades.get(i);

                if(current_state.size <= blade.max_size) {
                    List<Double> next_sizes = new ArrayList<>();
                    next_sizes.add((double)t);

                    for(int j = i + 1; j < blades.size(); j++) {
                        Blade next_blade = blades.get(j);
                        if(next_blade.max_size < current_state.size && next_blade.max_size <= blade.max_size) {
                            next_sizes.add((double)next_blade.max_size);
                        }
                    }

                    for(double new_size : next_sizes) {
                        if(new_size >= current_state.size) continue;
                        double extra_time = blade.halve_time * Math.log(current_state.size / new_size) / Math.log(2);
                        pq.add(new State(new_size, current_state.time + extra_time));
                    }
                } else {
                    break;
                }
            }
        }
        System.out.println(-1);

    }

}
class Blade{
    public int max_size; //max size
    public int halve_time; // time to halve

    public Blade(int m, int h){
        this.max_size = m;
        this.halve_time = h;
    }
}

class State{
    double size;
    double time;
    public State(double size, double time){
        this.size = size;
        this.time = time;
    }

}
