object1 to objecto with relation(context1)

son with mother in a context of a family
son with mother in a context of university


context1
	object1 as role1
	object2 as role2
	...
	objectN as roleN

example:

family
	Invan Ivanovich as son
	Anna Konstantinovna as mother

class son in man
{
	const 
}

role mother is woman
{
	const 
}

class child: man | woman
{
}

class man:human
{
	const gender gender = male;
}

class woman:human
{
	const gender gender = female;
}

class human:entity
{
	string firstName,
	int age,
	gender gender
}

class entity
{
}



enum gender
{
	female,
	male
}


// Human is a something abstract
abstract class human (because human is a something abstract)
{
	enum gender gender;
	int age;
}
// But man or woman more conctete but also abstract
abstract class man : human
{
	// Restriction that differ man from another successors of the human
	const human::gender = gender.male;
}

abstract class woman : human
{
	// Restriction that differ woman from another successors of the human
	const human::gender = gender.woman;
}

set human
{
	gender,
	eye color
}

set gender = {female, male};
set eye color = {both_blue, both_gray, both_green, both_brown, left_green_right_blue};
set name = {Ivan Ivanov, Ivan Petrov, ... n};

M(gender) = 2
M(eye_color) = 5;

M(human) = M(gender) x M(eye color) ... x M(n)

M(human) = 2 x 5 = 10;

human = {{female, both_blue}, {female, both_gray}, ...};






human classes = {}
	human classes = human sub-class 1 x ... x human sub-class n

	sub-class is a class where to the some properties assigned restrictions


man ) human | gender = male
woman ) human

gendered classes) human x gender where gender {female, male};
eye colorer ) human x eye color where eye color {blue, gray, green, brown};
...
classes humans = gendered x eye colored;

!RESTRICTIONS & EXTENSIONS

human is more generic entity than man or woman. That is why we should to apply restrictions to the some of the properties of the human for each of them to create variations of the human.


object in family should be a human

son role in family: object should have a gended and be male, should have an age
mother role in family: object should have a gender and  be female, should have an age

son, mother on family
	mother.age > son.age
	
