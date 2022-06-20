#pragma once

struct wezel {
  int i;
  int j;
  int nr;
  int prev;

  void operator=(wezel temp) {
    this->i = temp.i;
    this->j = temp.j;
    this->nr = temp.nr;
    this->prev = temp.prev;
  }
};

struct miejsce {
  int i;
  int j;
};
