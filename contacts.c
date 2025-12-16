#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "contacts.h"
char first_names[500][50];
char last_names[500][50];
char phone_numbers[500][20];
char emails[500][100];
int ids[500];
int count = 0;
int verify_email(char emails[50]){
  int at = 0, dot = 0;
  for(int i = 0; emails[i]!= '\0'; i++){
    if(emails[i] == '@'){
      at = 1;
    }            
    else if(emails[i] == '.'){
      dot = 1;
    }
  }        
  return(at && dot);
}
void add_contact(){    
char fname[50];    
char lname[50];    
char email[100];    
char phone[16];    
int id;    
while(1){	
  printf("First Name: ");
  scanf("%49s", fname);
  if(strlen(fname) == 0){
    printf("Please input a firstname.\n");
    continue;
  }
  break;
}
while(1){	printf("Last Name: ");
         scanf("%49s", lname);
         if(strlen(lname) == 0){
           printf("Please input a lastname.\n");
           continue;
         }	
         break;
        }
while(1){
printf("Phone: ");
scanf("%15s", phone);
int len = strlen(phone);
if(len < 7 || len > 15){
  printf("Phone number must be between 7 - 15 digits.\n");
  continue;	}	for(int i = 0; i < len ; i++){
  if(!isdigit(phone[i])){
    printf("Phone number must be digits.\n");
    continue;
  }                
}	break;
}
while(1){
printf("Email: ");
scanf("%99s", email);
if(strlen(email) == 0){
  continue; 
}	
  int hasSpace = 0;	
  for(int i = 0; email[i]!= '\0'; i++){	
    if(email[i] == ' '){	
      hasSpace = 1;	
      break;  
    }	    
  }	if(hasSpace){	
    printf("No space allowed in emails.\n");	
    continue;	}	int isEmail = verify_email(email);
  if( isEmail != 1){	
    printf("Email must contain @ and .\n");
    continue;
  }	
  break;
}	    
  ids[count] = (count == 0)? 1: (ids[count-1] +1);   
  strcpy(first_names[count], fname); 
  strcpy(last_names[count], lname);  
  strcpy(emails[count], email);  
  strcpy(phone_numbers[count], phone); 
  count++; 
  printf("Contact added successfully.\n");
}
void get_contact_by_id(){ 
  int id;   
  printf("Enter ID: ");   
  scanf("%d", &id);    
  for(int i = 0; i < count; i++){  
    if(id == ids[i]){  
      printf("ID: %d\nFirst Name: %s\nLast Name: %s\nPhone: %s\nEmail: %s\n", id, first_names[i], last_names[i], phone_numbers[i], emails[i]);   
      return;   
    }   
  }   
  printf("Contact not found\n");
}
void list_contacts(){  
if(count ==0){   
  printf("No contacts available.\n"); 
  return;  
}  
printf("%-2s | %-2s | %-2s | %-2s | %-2s\n", "ID","First Name", "Last Name", "Phone Number", "Email"  ); //We can use format specifiers for actual strings  
printf("--------------------------------------------------------------------------------------------\n"); 
  for(int i = 0; i < count; i++){    
    printf("%-2d | %-2s | %-2s | %-2s | %-2s\n", ids[i],first_names[i],last_names[i],phone_numbers[i],emails[i]); 
  }
}
void update_contact_by_id(){ 
  char fname[50];   
  char lname[50];   
  char email[100];    
  char phone[16];  
  int id;   
  printf("Enter the ID to update: "); 
  scanf("%d", &id); 
  int index = -1;  
  for(int i = 0; i < count; i++){   
    if(ids[i] == id){   
      index = i;    
      break;   
    } 
  }   
  if(index == -1){    
    printf("Contact not found.\n"); 
    return;   
  }   
  printf("Updating contact ID %d\n", id);   
  while(1){		printf("First Name: ");     
           scanf("%49s", fname);          
           if(strlen(fname) == 0){              
             printf("Please input a firstname.\n");       
             continue;              
           }		break;         
          }        
  while(1){		
    printf("Last Name: ");           
    scanf("%49s", lname);            
    if(strlen(lname) == 0){                 
      printf("Please input a lastname.\n");          
      continue;           
    }		
    break;      
  }	    
  while(1){		 
    printf("Phone: ");      
    scanf("%15s", phone);    
    int len = strlen(phone);
    if(len < 7 || len > 15){   
      printf("Phone number must be between 7 - 15 digits.\n");
      continue;           
    }	
    int valid = 1;		
    for(int i = 0; i < len; i++){  
      if(!isdigit(phone[i])){		
        valid = 0;		
        break;	
      }		
    }		 
    if(!valid){		
      printf("Phone number must be digits.\n");			 
      continue;		  
    }		  
    break;	   
  }		    
  while(1){		  
    printf("Email: ");          
    scanf("%99s", email);      
    if(strlen(email) == 0){     
      printf("Please input an email.\n"); 
      continue;      
    }		   
    int hasSpace = 0;    
    for(int i = 0; email[i]!= '\0'; i++){   
      if(email[i] == ' '){    
        hasSpace = 1;		
        break;      
      }             
    }		    
    if(hasSpace){		
      printf("No space allowed in emails.\n");	
      continue;		
    }               
    int isEmail = verify_email(email);    
    if( isEmail != 1){     
      printf("Email must contain @ and .\n");  
      continue;      
    }		 
    break;  
  }    
  strcpy(first_names[index], fname);   
  strcpy(last_names[index], lname);  
  strcpy(phone_numbers[index], phone);  
  strcpy(emails[index], email); 
}
void delete_contact_by_id(){    
int id;   
printf("Enter ID: ");   
scanf("%d", &id);  
if(count == 0){	  
  printf("No contact to delete.\n");	
  return;  
}   
int index = -1;    
for(int i = 0; i < count; i++){	
  if(ids[i] == id){		 
    index = i;	
    break;	 
  }  
}   
if(index == -1){	  
  printf("Contact not found.\n");	
  return; 
} 
for(int i = index; i < count - 1; i++){	
  ids[i]  = ids[i+1];    
  strcpy(first_names[i], first_names[i+1]);  
  strcpy(last_names[i], last_names[i+1]);  
  strcpy(phone_numbers[i], phone_numbers[i+1]);	 
  strcpy(emails[i], emails[i+1]);
}   
count--;  
printf("Contact deleted");
}
