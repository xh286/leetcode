class SnakeGame {
private:
    queue<pair<int,int>> snake; // queue.size() is snake length. queue.front() is tail, queue.back() is head.
    vector<vector<bool>> occupied;
    queue<pair<int,int>> foods;
    int m;
    int n;
    bool game_over;
    bool newPosInvalid(int row, int col)
    {
        return(row>=0 && row<m && col>=0 && col<n);
    }

public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) : m(height), n(width), game_over(false) {
        occupied = vector<vector<bool>>(m,vector<bool>(n,false));
        if(m<=0 || n<=0) 
        {
            game_over = true;
        }
        else
        {
            occupied[0][0] = true;
            snake.push({0,0});
            for(auto it=food.begin(); it!=food.end();it++)
                foods.push(*it);
        }
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if(game_over) return -1;
        int row = snake.back().first;
        int col = snake.back().second;
        char dir = direction[0];
        switch(dir)
        {
            case 'U': row--; break;
            case 'D': row++; break;
            case 'L': col--; break;
            case 'R': col++; break;
            default: game_over=true; return -1;
        }
        if(newPosInvalid(row,col)){game_over=true; return -1;}
        auto food = foods.front();
        if(!(row==food.first && col==food.second))
        {
            auto tail = snake.front();
            occupied[tail.first][tail.second] = false;
            snake.pop();
        }
        else
            foods.pop();
        if(occupied[row][col]){game_over=true; return -1;}
        occupied[row][col] = true;
        snake.push({row,col});
        return snake.size()-1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */