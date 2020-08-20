#include <cstdlib>
#include "RecipeList.h"
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;

int main()
{
  bool running = true;
  std::string input;
  int selection;
  RecipeList currentList = RecipeList();

  while(running){
    std::cout << "Enter option number\n";
    std::cout << "1. Import recipes.\n";
    std::cout << "2. Add recipe.\n";
    std::cout << "3. Modify recipe.\n";
    std::cout << "4. Delete Recipe.\n";
    std::cout << "5. Find recipe by ingredients.\n";
    std::cout << "6. Get random recipe.\n";
    std::cout << "7. Browse recipes.\n";
    std::cout << "8. Select recipe.\n";
    std::cout << "9. Exit program.\n";
    std::cout << std::endl;
    while(true){
      std::getline (std::cin, input);
      std::stringstream myStream(input);
      if (myStream >> selection){
        if (selection >= 1 && selection <= 9){
          break;
        }
      }
      std::cout << "Invalid input. Enter a number between 1 and 9.\n";
    }
    switch(selection){
      //Import recipes
      case 1:
      {
        currentList.importAll();
        break;
      }
      //Add recipe
      case 2:
      {
        currentList.addRecipe();
        break;
      }
      //Modify recipe
      case 3:
      {
        std::string input;
        currentList.printRecipeNames();
        std::cout << "Enter the name of the recipe to modify or Q to quit.\n";
        std::getline(std::cin, input);
        while(true){
          if (input == "Q"){
            break;
          }
          else{
            bool found = currentList.findRecipe(input);
            if (found){
              currentList.changeRecipe(input);
              break;
            }
            else{
              std::cout << "Recipe not found.\n";
              std::cout << "Enter the name of the recipe to modify or Q to quit.\n";
              std::getline(std::cin, input);
            }
          }
        }
        break;
      }
      //Delete recipe
      case 4:
      {
        std::string input;
        currentList.printRecipeNames();
        std::cout << "Enter the name of the recipe you want to delete or Q to quit.\n";
        std::getline(std::cin, input);
        while(true){
          if (input == "Q"){
            break;
          }
          else{
            bool found = currentList.findRecipe(input);
            if (found){
              currentList.removeRecipe(input);
              break;
            }
            else{
              std::cout << "Recipe not found.\n";
              std::cout << "Enter the name of the recipe you want to delete or Q to quit.\n";
              std::getline(std::cin, input);
            }
          }
        }
        break;
      }
      //Find recipe by ingredients
      case 5:
      {
        break;
      }
      //Get random recipe
      case 6:
      {
        break;
      }
      //Browse recipes
      case 7:
      {
        currentList.printRecipeNames();
        std::cout << std::endl;
        break;
      }
      //Select recipe
      case 8:
      {
        break;
      }
      //Exit program
      case 9:
      {
        running = false;
        break;
      }
    }
  }
  // RecipeList currentList = RecipeList();
  // currentList.importAll();
  // currentList.printRecipeNames();
  // currentList.changeRecipe("r2");




  //currentList.removeRecipe("val");
  //currentList.findRecipe("val");
  //cout << "FBI\n";
  //currentList.findByIngredient("1");

  return 0;
}


//TODO List
/*
PRINT INSTRUCTIONS MAY NOT WORK!
Fix printIngredients-DONE
Implement cooking directions-DONE
Find recipes with specific ingredients-DONE
Export data-DONE
Import data-DONE
Flip ingredient and ingredient amount
********************************************
//Possible features
Frequency statistic

Sorting system

Find which ingredients are the most common throughout all recipes
Whichever recipe contains the most common ingredients will be placed first in recipeList


Searching by ingredients

Returns array of pointers to recipes inside recipeList
if ingredient exists inside recipe, add the recipe to the array of pointers
*/
