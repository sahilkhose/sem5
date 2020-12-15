--<ScriptOptions statementTerminator="!"/>

CREATE SCHEMA UNIVERSITY_1!

CREATE TABLE UNIVERSITY_1.STUDENT (
		STUDENT_ID VARCHAR(10) NOT NULL,
		STUDENT_NAME VARCHAR(10),
		DEPTID VARCHAR(10)
	)
	DATA CAPTURE NONE!

CREATE TABLE UNIVERSITY_1.DEPARTMENT (
		DEPT_ID VARCHAR(10) NOT NULL,
		DEPT_NAME VARCHAR(10),
		LOCATION VARCHAR(10)
	)
	DATA CAPTURE NONE!

ALTER TABLE UNIVERSITY_1.STUDENT ADD CONSTRAINT STUDENT_PK PRIMARY KEY
	(STUDENT_ID)!

ALTER TABLE UNIVERSITY_1.DEPARTMENT ADD CONSTRAINT DEPARTMENT_PK PRIMARY KEY
	(DEPT_ID)!

ALTER TABLE UNIVERSITY_1.STUDENT ADD CONSTRAINT STUDENT_DEPARTMENT_FK FOREIGN KEY
	(DEPTID)
	REFERENCES UNIVERSITY_1.DEPARTMENT
	(DEPT_ID)
	ON DELETE CASCADE!

