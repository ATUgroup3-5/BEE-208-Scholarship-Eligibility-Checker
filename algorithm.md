Algorithm

1. Start the program.
2. Display the title **"Scholarship Eligibility Checker"**.
3. Ask the user to enter the number of students.
4. Create or open the 'scholarship_report.text' for writing.
5. Initialize the eligible student count and the not-eligible student count to zero.
6. Repeat the following steps for each student.
 -  Enter the student's name.
 -  Enter the student's index number.
 -  Enter the student's program.
 -  Enter the student's level.
 -  Enter the student's GPA.
 -  Validate that the GPA is between 0.0 and 4.0. If it is invalid, ask the user to enter it again.
 -  Enter the student's attendance percentage.
 -  Validate that the attendance percentage is between 0 and 100. If it is, ask the user to enter it again.
 -  Enter the student's conduct status (Good or Poor).
 -  Determine the student's scholarship eligibility:
    - If the GPA is 3.5 or above, attendance is 80% or above, and conduct is Good, declare the student is Eligible for Scholarship.
    - If GPA is below 3.5, declare Not Eligible- GPA below requirement.
    - If attendance is below 80%, declare Not Eligible- Attendance below requirement.
    - If conduct is Poor, declare Not Eligible- conduct requirement not met.
 -  Display the student's details and eligibility result.
 -  Save the student's details and eligibility result into 'scholarship_report.text'.
 -  Update the eligible or not-eligible student count.
7. Display the total number of eligible students.
8. Display the total number of not eligible students.
9. Save the summary report into 'scholarship_report.txt'.
10. Close the report file.
11. Display a confirmation message that the report has been saved successfully.
12. End the program.
