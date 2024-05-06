public class MarkSheet {
    public String studentName;
    public String rollNumber;
    public Map<String, Integer> subjectMarks;
    public Integer totalMarks;
    public Decimal percentage;

    public MarkSheet(String name, String roll, Map<String, Integer> marks) {
        studentName = name;
        rollNumber = roll;
        subjectMarks = marks;
        totalMarks = calculateTotalMarks();
        percentage = calculatePercentage();
    }

    private Integer calculateTotalMarks() {
        Integer total = 0;
        for (Integer marks : subjectMarks.values()) {
            total += marks;
        }
        return total;
    }

    private Decimal calculatePercentage() {
        return (Decimal.valueOf(totalMarks) / (subjectMarks.size() * 100)) * 100;
    }

    public Decimal calculateAverageOfThreeSubjects() {
        Integer sum = 0;
        for (Integer marks : subjectMarks.values()) {
            sum += marks;
        }
        return Decimal.valueOf(sum) / 3; // Return average of three subjects
    }
}
/*


Map<String, Integer> marks = new Map<String, Integer>{
    'Maths' => 90,
    'Science' => 85,
    'English' => 88
};

MarkSheet markSheet = new MarkSheet('John Doe', '12345', marks);

System.debug('Student Name: ' + markSheet.studentName);
System.debug('Roll Number: ' + markSheet.rollNumber);
System.debug('Total Marks: ' + markSheet.totalMarks);
System.debug('Percentage: ' + markSheet.percentage);
System.debug('Subject Marks: ' + markSheet.subjectMarks);
System.debug('Average Marks: ' + markSheet.calculateAverageOfThreeSubjects());


*/