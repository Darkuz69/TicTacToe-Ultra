//Self-Project #??
//TIC TAC TOE (HUMAN VS AI)
//Darkuz_69

#include <iostream>

#define MAX_SQUARE 9

int check_win(char* board, char symbol_ai, char symbol_player) {

  int win_status = 0; //0 - No one, -10 - Player, 10 - AI

  //HORIZONTAL
  for(int i = 0; i < MAX_SQUARE; i += 3) {
    if(board[i] == symbol_player && board[i+1] == symbol_player && board[i+2] == symbol_player) {
      win_status = -10;
    } else if(board[i] == symbol_ai && board[i+1] == symbol_ai && board[i+2] == symbol_ai) {
      win_status = 10;
    } 
  }

  //VERTICAL
  for(int i = 0; i < 3; i++) {    
    if(board[i] == symbol_player && board[i+3] == symbol_player && board[i+6] == symbol_player) {
      win_status = -10;
    } else if(board[i] == symbol_ai && board[i+3] == symbol_ai && board[i+6] == symbol_ai) {
      win_status = 10;
    } 
  }

  //DIAGONAL
  if((board[0] == symbol_player && board[4] == symbol_player && board[8] == symbol_player) || (board[2] == symbol_player && board[4] == symbol_player && board[6] == symbol_player)) {
    win_status = -10;
  } else if((board[0] == symbol_ai && board[4] == symbol_ai && board[8] == symbol_ai) || (board[2] == symbol_ai && board[4] == symbol_ai && board[6] == symbol_ai)) {
    win_status = 10;
  } 

  return win_status;

}

//Checks if board is full
bool isFull(char* board) {
  for(int i = 0; i < MAX_SQUARE; i++) {
    if(board[i] == '_') {
      return false;
    }
  }
  return true;
}

int minimax(char* board, char symbol_ai, char symbol_player, int depth, bool isMax) {

  //Check if someone win, then return the score
  int result = check_win(board, symbol_ai, symbol_player);
  if(result != 0) {
    return result;
  }

  //Board full checker
  bool isfull = isFull(board);
  if(isfull) {
    return 0;
  }

  if(isMax) {
    int best_score = -1000;
    for(int i = 0; i < MAX_SQUARE; i++) {
      if(board[i] == '_') {
        board[i] = symbol_ai;
        int current_score = minimax(board, symbol_ai, symbol_player, 0, false);
        board[i] = '_';
        if(current_score > best_score) {
          best_score = current_score;
        }
      }
    }
    return best_score;
  } else {
    int best_score = 1000;
    for(int i = 0; i < MAX_SQUARE; i++) {
      if(board[i] == '_') {
        board[i] = symbol_player;
        int current_score = minimax(board, symbol_ai, symbol_player, 0, true);
        board[i] = '_';
        if(current_score < best_score) {
          best_score = current_score;
        }
      }
    }
    return best_score;
  }
  

}

void AI_move(char* board, char symbol_ai, char symbol_player) {

  int best_score = -1000;
  int best_move;
  for(int i = 0; i < MAX_SQUARE; i++) {
    if(board[i] == '_') {
      board[i] = symbol_ai;
      int current_score = minimax(board, symbol_ai, symbol_player, 0, false);
      board[i] = '_';
      if(current_score > best_score) {
        best_score = current_score;
        best_move = i;
      }
    }
  }

  board[best_move] = symbol_ai;

}

void show_board(char* board){

  std::cout << "=========================\n";
  std::cout << "|       |       |       |\n";
  std::cout << "|   "<<board[0]<<"   |   "<<board[1]<<"   |   "<<board[2]<<"   |\n";
  std::cout << "|       |       |       |\n";
  std::cout << "=========================\n";
  std::cout << "|       |       |       |\n";
  std::cout << "|   "<<board[3]<<"   |   "<<board[4]<<"   |   "<<board[5]<<"   |\n";
  std::cout << "|       |       |       |\n";
  std::cout << "=========================\n";
  std::cout << "|       |       |       |\n";
  std::cout << "|   "<<board[6]<<"   |   "<<board[7]<<"   |   "<<board[8]<<"   |\n";
  std::cout << "|       |       |       |\n";
  std::cout << "=========================\n";

}

void guide_board(){

  int i = 0;

  std::cout << "=========================\n";
  std::cout << "|       |       |       |\n";
  std::cout << "|   "<< i+1 <<"   |   "<<i+2<<"   |   "<<i+3<<"   |\n";
  std::cout << "|       |       |       |\n";
  std::cout << "=========================\n";
  std::cout << "|       |       |       |\n";
  std::cout << "|   "<<i+4<<"   |   "<<i+5<<"   |   "<<i+6<<"   |\n";
  std::cout << "|       |       |       |\n";
  std::cout << "=========================\n";
  std::cout << "|       |       |       |\n";
  std::cout << "|   "<<i+7<<"   |   "<<i+8<<"   |   "<<i+9<<"   |\n";
  std::cout << "|       |       |       |\n";
  std::cout << "=========================\n";

}

int main() {

  char main_board[MAX_SQUARE];
  for(int i = 0; i < MAX_SQUARE; i++) {
    main_board[i] = '_';
  }
  char symbol_ai, symbol_player, response;
  bool player_first;
  int win_status = 0;

  system("clear");

  do {
    std::cout << "  Choose your symbol(X/O): ";
    std::cin >> symbol_player;
    if(symbol_player != 'X' && symbol_player != 'x' && symbol_player != 'O' && symbol_player != 'o') {
      std::cout << "  Try again!\n";
    } else if(symbol_player == 'X' || symbol_player == 'x' || symbol_player == 'O' || symbol_player == 'o') {
      break;
    }
  } while(true);

  if(symbol_player == 'X' || symbol_player == 'x') {
    symbol_ai = 'O';
  } else {
    symbol_ai = 'X';
  }

  do {
    std::cout << "  Would you like to go first?(Y/N): ";
    std::cin >> response;
    if(response != 'Y' && response != 'y' && response != 'N' && response != 'n') {
      std::cout << "  Try again!\n";
    } else if(response == 'N' || response == 'n' || response == 'Y' || response == 'y') {
      break;
    }
  } while(true);

  if(response == 'Y' || response == 'y') {
    player_first = true;
  } else {
    player_first = false;
  }

  if(player_first) {
    int counter = 0;
    while(counter < MAX_SQUARE) {
      int index = 0;
      system("clear");
      guide_board();
      std::cout << "\n";
      show_board(main_board);
      std::cout << "  Your turn...\n";
      do {
        std::cout << "  Enter index: ";
        std::cin >> index;
        if(main_board[index-1] != '_') {
          std::cout << "  Try again!\n";
        } else {
          break;
        }
      } while(true);
      main_board[index-1] = symbol_player;
      win_status = check_win(main_board, symbol_ai, symbol_player);
      if(win_status != 0) {
        break;
      }
      if(isFull(main_board)) {
        break;
      }
      AI_move(main_board, symbol_ai, symbol_player);
      std::cout << "  The AI made its move...\n";
      win_status = check_win(main_board, symbol_ai, symbol_player);
      if(win_status != 0) {
        break;
      }
      getchar();
      std::cout << "  Press enter to continue...";
      std::cin.get();
      counter++;
    }
  } else {
    int counter = 0;
    while(counter < MAX_SQUARE) {
      int index = 0;
      system("clear");
      AI_move(main_board, symbol_ai, symbol_player);
      win_status = check_win(main_board, symbol_ai, symbol_player);
      if(win_status != 0) {
        break;
      }
      if(isFull(main_board)) {
        break;
      }
      guide_board();
      std::cout << "\n";
      show_board(main_board);
      std::cout << "  The AI made its move..,.\n";
      std::cout << "  Your turn...\n";
      do {
        std::cout << "  Enter index: ";
        std::cin >> index;
        if(main_board[index-1] != '_') {
          std::cout << "  Try again!\n";
        } else {
          main_board[index-1] = symbol_player;
          break;
        }
      } while(true);
      win_status = check_win(main_board, symbol_ai, symbol_player);
      if(win_status != 0) {
        break;
      }
      getchar();
      std::cout << "  Press enter to continue...";
      std::cin.get();
      counter++;
    }
  }

  system("clear");
  guide_board();
  std::cout << "\n";
  show_board(main_board);

  if(win_status == 10) {
    std::cout << "  AI wins!!\n";
  } else if(win_status == -10) {
    std::cout << "  You win!!\n";
  } else {
    std::cout << "  It's a draw!!\n";
  }

  return 0;

}
