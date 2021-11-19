-- student who took all course offered by Biology
insert into student values ('101950', 'ILikeBio', 'Biology', 100);
insert into takes values 
select *
from student
where (
  select count(course.course_id)
  from takes, course
  where student.ID = takes.ID AND course.dept_name = 'Biology'
) = (
  select count(course_id)
  from course
  where dept_name = 'Biology'
);

-- 3.1
-- a
select title
from course
where dept_name = 'Comp.Sci' and credits = 3;
-- b
select distinct takes.ID
from takes, instructor, teaches
where takes.course_id = teaches.course_id and
takes.sec_id = teaches.sec_id and
takes.semester = teaches.semester and
takes.year = teaches.year and
teaches.id = instructor.id and
instructor.name = 'Einstein';
-- c
select max(salary)
from instructor;
-- d
select ID, name
from instructor
where salary = (select max(salary) from instructor);
-- e
select course_id, sec_id, count(ID) as enrollment
from takes natural join section
where year = 2017 and semester = 'Fall'
group by course_id, sec_id;

select course_id, sec_id, (
  select count(ID)
  from takes
  where takes.year = section.year
  and takes.course_id = section.course_id
  and takes.semester = section.semester
  and takes.sec_id = section.sec_id
) as enrollment
from section
where year = 2017 and semester = 'Fall'
-- f
select max(enrollment)
from (
  select course_id, sec_id, count(ID) as enrollment
  from takes natural join section
  where year = 2017 and semester = 'Fall'
  group by course_id, sec_id
) as A;
-- g
with enrollment_info as (
  select course_id, sec_id, count(ID) as enrollment
  from takes natural join section
  where year = 2017 and semester = 'Fall'
  group by course_id, sec_id
) 
select course_id, sec_id, enrollment
from enrollment_info
where enrollment = (select max(enrollment) from enrollment_info);

-- 3.2
create table grade_points (
  grade varchar(2),
  points numeric(2, 1) not null,
  primary key (grade)
);
insert into grade_points values
  ('A', 4),
  ('A-', 3.7),
  ('B+', 3.3),
  ('B', 3),
  ('B-', 2.7),
  ('C+', 2.3),
  ('C', 2),
  ('C-', 1.7)
;
insert into student values ('12345', 'Testtesttest', 'Biology',66);
-- student who do not take courses
insert into student values ('54321','testtest','Math', 0);
insert into takes values
('12345','239','1','Fall',2006,'A'),
('12345','802','1','Spring',2003,'B+'),
('12345','642','1','Fall',2004,'C+');

-- a
select ID, sum(points*credits) as grade_points
from takes, course, grade_points
where takes.course_id = course.course_id and takes.grade = grade_points.grade
group by ID
having ID = '12345';
/*
select sum(credits*points)
from takes, course, grade_points
where ID = '12345' and takes.course_id = course.course_id and takes.grade = grade_points.grade;
*/

-- b
select ID, sum(points*credits)/sum(credits) as GPA
from takes, course, grade_points
where takes.course_id = course.course_id and takes.grade = grade_points.grade
group by ID
having ID = '12345';
/*
select sum(credits*points)/sum(credits)
from takes, course, grade_points
where ID = '12345' and takes.course_id = course.course_id and takes.grade = grade_points.grade;
*/
-- c
select ID, sum(points*credits)/sum(credits) as GPA
from takes, course, grade_points
where takes.course_id = course.course_id and takes.grade = grade_points.grade
group by ID;

-- 3.3
-- a
update instructor
set salary = 1.1*salary
where dept_name = 'Comp. Sci';
-- b
delete from course
where course_id not in (select course_id from section);
-- select *
-- from course
-- where course_id not in (select course_id from section);
-- c
insert into instructor
select ID, name, dept_name, 10000
from student
where tot_cred > 100;

-- 3.11
-- a
select distinct name
from student, takes, course
where student.id = takes.id and takes.course_id = course.course_id and course.dept_name = 'Comp. Sci';
-- b
select id, name
from student
where not exists (
  select *
  from takes
  where takes.id = student.id and takes.year < 2009
);
-- select *
-- from student natural join takes
-- where student.id = '12345';
-- c
(select dept_name, max(salary)
from instructor
group by dept_name)
union
(select dept_name, null
from department
where not exists(select * from instructor where instructor.dept_name = dept_name));
-- d
select min(max_salary) as min_max_salary
from (
  (select dept_name, max(salary) as max_salary
  from instructor
  group by dept_name)
  union
  (select dept_name, null
  from department
  where not exists(select * from instructor where instructor.dept_name = dept_name))
) as tmp;

select dept_name, salary
from instructor
where salary = (select min(max_salary)
                from (
                  (select dept_name, max(salary) as max_salary
                  from instructor
                  group by dept_name)
                  union
                  (select dept_name, null
                  from department
                  where not exists(select * from instructor where instructor.dept_name = dept_name))
                ) as A);
-- 3.12
-- a
insert into course values ('001', 'Weekly Seminar', 'Comp. Sci.', 1); -- 0 is not allowed
-- b
insert into section values ('001', '1', 'Fall', 2009, null, null, null);
-- c
insert into takes
select ID, course_id, sec_id, semester, year
from student, section
where student.dept_name = 'Comp. Sci.' and section.course_id = '001' and section.sec_id = '1';
-- select count(*)
-- from student
-- where dept_name = 'Comp. Sci.'
-- d
insert into student values ('10086', 'Chavez', 'Comp. Sci.', 101);
insert into takes values ('10086', '001', '1', 'Fall', 2009, null);

select *
from takes
where ID = (select ID from student where name = 'Chavez');

delete from takes
where ID = (select ID from student where name = 'Chavez') and course_id = '001' and sec_id = '1';