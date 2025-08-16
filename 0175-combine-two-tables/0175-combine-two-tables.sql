/* Write your T-SQL query statement below */
Select  Person.firstName, Person.lastName, Address.city , Address.state
From Address
right Join [Person]
On Address.personId = Person.personId;