#include "RecipeList.h"

//Declaration
RecipeList::RecipeList(){
  nextRecipe = NULL;
  previousRecipe = NULL;
  current = new Recipe();
}


//setters
void RecipeList::addRecipe(){
  std::string rName;
  int cTime;
  int pTime;
  bool ingredientInput = false;

  std::string input;

  std::cout << "Input recipe name: ";
  std::getline (std::cin, rName);
  std::cout << std::endl;

  std::cout << "Input cooking time: ";
  std::cin >> cTime;
  std::cout << std::endl;

  std::cout << "Input preparation time: ";
  std::cin >> pTime;
  std::cout << std::endl;
  //Recipe* temp = new Recipe(rName, cTime, pTime);

  std::cout << "Input ingredient name with amount and unit after a :\n";
  std::cout << "Example: water:10ml\n";
  std::cout << "When finished inputting ingredients, type exit to leave ingredient input\n";

  while(ingredientInput == false){
    char c = ':';
    std::getline(std::cin, input);
    if (input != "exit"){
      size_t location = input.find(c);
      std::string tempName = input.substr(0, location);
      std::string tempAmount = input.substr(location + 1, input.size() - location);
      current->addIngredient(tempName);
      current->addIngredientAmount(tempAmount);
    }
    else{
      ingredientInput = true;
    }
  }
}

//getters
int RecipeList::recipeAmount(){
  return listRecipe.size();
}

Recipe* RecipeList::getCurrentRecipe(){
  return current;
}

Recipe* RecipeList::getNextRecipe(){
  return nextRecipe;
}

Recipe* RecipeList::getPreviousRecipe(){
  return previousRecipe;
}
