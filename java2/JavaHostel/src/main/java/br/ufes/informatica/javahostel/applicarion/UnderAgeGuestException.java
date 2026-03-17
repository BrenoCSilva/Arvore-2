package br.ufes.informatica.javahostel.applicarion;

public class UnderAgeGuestException extends Exception {

	
	private int age;

	public UnderAgeGuestException(int age) {
		super();
		this.age = age;
	}
	
	public int getAge() {
		return age;
	}
	
}
