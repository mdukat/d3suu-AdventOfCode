import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        File file = new File("data.txt");
        Scanner scanner = new Scanner(file);

        int part1Counter = 0;
        int part2Counter = 0;

        while(scanner.hasNextLine()) {
            String input = scanner.nextLine();

            // 0 = values
            // 1 = character
            // 2 = password
            String[] tokens = input.split(" ");

            String[] values = tokens[0].split("-");
            int min = Integer.parseInt(values[0]);
            int max = Integer.parseInt(values[1]);
            int counter = 0;

            char letter = tokens[1].toCharArray()[0];

            char[] password = tokens[2].toCharArray();

            // part 1
            for(char pchar : password){
                if(pchar == letter)
                    counter++;
            }

            if(counter >= min && counter <= max)
                part1Counter++;

            // part 2
            // Elfs dont start indexes at 0 or something
            min--;
            max--;

            // A XOR B
            if(password[min] == letter ^ password[max] == letter)
                part2Counter++;
        }

        System.out.println(part1Counter);
        System.out.println(part2Counter);
    }
}
