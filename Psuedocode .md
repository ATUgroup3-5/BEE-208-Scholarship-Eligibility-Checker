Pseudocode

BEGIN

     DISPLAY " SCHOLARSHIP ELIGIBILITY CHECKER".

     INPUT numberOfStudents
      
     OPEN scholarship_report.txt

     SET eligibleCount = 0

     SET notEligibleCount = 0

     FOR student = 1 TO numberOfStudents DO

         INPUT studentName

         INPUT indexNumber

         INPUT program

         INPUT level

         INPUT GPA

         WHILE GPA < 0 OR GPA > 4 DO

           DISPLAY "Invalid GPA.Please enter a GPA between 0.0 and 4.0

           INPUT GPA

         END WHILE

         INPUT conuctStatus

         IF GPA >= 3.5 AND attendancePercentage >= 80 AND conductStatus = "Good" THEN

            SET eligibilityStatus = "Eligible for Scholarship"

            eligibleCount = eligibleCount + 1

         ELSE IF GPA <3.5 THEN

              SET eligibilityStatus = " Not Eligible - GPA below requirement"

              notEligibleCount = notEligibleCount + 1

         ELSE IF attendancePercentage < 80 THEN

           SET eligibilityStatus = "Not Eligible - Attendannce below requirement"

           notEligibleCount = notEligibleCount + 1

         ELSE

           SET eligibilityStatus = " Not Eligible - Conduct requirement nnot met"

           notEligibleCount = notEligibleCount + 1 

         
         END IF

         DISLAY studentName

         DISPLAY indexNumber

         DISPLAY programme

         DISPLAY level

         DISPLAY GPA

         DISPLAY attendancePercentage

         DISPLAY conductStatus

         DISPLAY eligibilityStatus

         WRITE student details TO'scholarship_report.txt'.

     END FOR

     DISPLAY "Total Eligible Student: ", eligibleCount

     DISPLAY "Total Not Eligible Students: ", notEligibleCount

     WRITE summary TO 'scholarship_report.txt'.

     CLOSE scholarship_report,txt

     DISPLAY "Report saved successfully as scholarship_report.txt".

 END

     