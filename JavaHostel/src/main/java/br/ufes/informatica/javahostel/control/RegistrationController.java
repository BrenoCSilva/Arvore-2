package br.ufes.informatica.javahostel.control;

import java.io.Serializable;

import javax.ejb.EJB;
import javax.enterprise.inject.Model;

import br.ufes.informatica.javahostel.domain.Guest;

@Model 
public class RegistrationController implements Serializable {
	
	@EJB
	private RegistrationService registrationService;
	
	private Guest guest = new Guest();
	
	private int age;
	
	
	getGuest 
}
