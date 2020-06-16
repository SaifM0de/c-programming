#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >=2 && c.value <=VALUE_ACE);
  assert(c.suit >=SPADES && c.suit <=CLUBS);

}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
  case STRAIGHT_FLUSH:
    return "STRAIGHT FLUSH";
    break;
  case FOUR_OF_A_KIND:
    return "FOUR OF A KIND";
    break;
  case FULL_HOUSE:
    return "FULL HOUSE";
    break;
  case FLUSH:
    return "FLUSH";
    break;
  case STRAIGHT:
    return "STRAIGHT";
    break;
  case THREE_OF_A_KIND:
    return "THREE OF A KIND";
    break;
  case TWO_PAIR:
    return "TWO PAIR";
    break;
  case PAIR:
    return "PAIR";
    break;
  case NOTHING:
    return "NOTHING";
    break; 
  }
  return EXIT_SUCCESS;
}

char value_letter(card_t c) {
  switch(c.value){
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
    return '0' + c.value;
    break;
  case 10:
    return '0';
    break;
  case 11:
    return 'J';
    break;
  case 12:
    return 'Q';
    break;
  case 13:
    return 'K';
    break;
  case 14:
    return 'A';
    break; 
  }
  return EXIT_SUCCESS;
}


char suit_letter(card_t c) {
  switch(c.suit){
  case SPADES:
    return 's';
    break;
  case HEARTS:
    return 'h';
    break;
  case DIAMONDS:
    return 'd';
    break;
  case CLUBS:
    return 'c';
    break;
  default:
    break;
  }
  return EXIT_SUCCESS;
}

void print_card(card_t c) {
  
  printf("%c%c", value_letter(c), suit_letter(c));
  
}


card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  suit_t suit;
  
  temp.value = value_let - '0';

  if(suit_let == 's' || suit_let == 'S'){
    temp.suit = suit_t SPADES;
  }
  else if(suit_let == 'h' || suit_let == 'H'){
    temp.suit = suit_t HEARTS;
  }
  else if(suit_let == 'd' || suit_let == 'D'){
    temp.suit = suit_t DIAMONDS;
  }
  else if(suit_let == 'c' || suit_let == 'C'){
    temp.suit = suit_t CLUBS;
  }
  else {
    printf("Invalid card suit entered.");
    EXIT_FAILURE;
  }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  for(int i = 0; i < 52; i++){
    temp.value = c % 13 + 2;
    temp.suit = c / 13;
  }
  
  return temp;
}
