/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:52:58 by igchurru          #+#    #+#             */
/*   Updated: 2025/06/16 17:00:42 by igchurru         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

# include "Harl.hpp"

Harl::Harl(void)		//	Constructor
{
	std::cout << "Harl object constructed" << std::endl;
}

Harl::~Harl(void)		//	Destructor
{
	std::cout << "Harl object destroyed"	<< std::endl;
}

Harl::complaintType	Harl::getComplaintLevel(std::string level)		// Helper function to change strings to int via an enum, since c98's switch cannot evaluate strings.
{
	if (level == "DEBUG")
		return Harl::DEBUG;
	else if (level == "INFO")
		return Harl::INFO;
	else if (level == "WARNING")
		return Harl::WARNING;
	else if (level == "ERROR")
		return Harl::ERROR;
	else
		return Harl::UNKNOWN;
}

void	Harl::complain(std::string level)		//	Decision-making function. Switch evaluates ints, not strings.
{
	Harl::complaintType scale;
	
	method_pointer functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};// Array of pointers to member functions. See Harl.hpp for details.

	scale = getComplaintLevel(level);
	switch (scale)
	{
		case DEBUG:		
		case INFO:
		case WARNING:
		case ERROR:
			(this->*functions[scale])();
			break ;
		
		case UNKNOWN:
			break ;
	}
}

void	Harl::debug(void)
{
	std::cout << "DEBUG: This is a generic complaint. I just love complaining." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO: Not getting over-the-top quality at half price will make me angry" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING: I am an entitled and bossy Harl and I will treat you like scum" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR: I want to speak to your manager!" << std::endl;
}
