// Copyright 2023 saito
#include "chapter14.h"


namespace chapter14 {
void execute() {
  Question1 q1;
  q1.exec();
}

void Question1::initialize() {
  std::cin >> N_ >> M_ >> s_;

  G_ = std::make_unique<std::vector<std::vector<Edge>>>(N_);

  for (int _ = 0; _ < M_; ++_) {
    int a, b, w;
    std::cin >> a >> b >> w;

    G_->at(a).push_back(Edge(b, w));
  }

  dist_.assign(N_, INT8_MAX);
  dist_[s_] = 0;
}
void Question1::bellman_ford_algo() {
  for (int _ = 0; _ < N_; ++_) {
    bool is_updated = false;

    for (int v = 0; v < N_; ++v) {
      if (dist_[v] == INT8_MAX)
        continue;

      for (auto e : G_->at(v)) {
        if(chmin(dist_[e.to_], dist_[v]+e.w_))
          is_updated = true;
      }
    }

    if (!is_updated) break;
  }
}
void Question1::exec() {
  initialize();
  bellman_ford_algo();

  const int max = *std::max_element(dist_.begin(), dist_.end());
  std::cout << max << std::endl;
}

void Question2::initialize() {
  std::cin >> N_ >> M_;
  G_ = std::make_unique<std::vector<std::vector<Node>>>(N_);

  dist_ = std::make_unique<std::vector<int>>();
  dist_->assign(N_, INT8_MAX);
  dist_->at(0) = 0;

  for (int i = 0; i < M_; ++i) {
    int a, b, w;
    std::cin >> a >> b >> w;

    G_->at(a).push_back(Node(b, w));
  }
}

void Question2::bellman_ford_algo() {
  for (int _ = 0; _ < N_; ++_) {
    bool is_updated = false;

    for (int v = 0; v < N_; ++v) {
      if (dist_->at(v) == INT8_MAX)
        continue;

      for (auto e : G_->at(v)) {
        is_updated = chmin(dist_->at(e.to_), dist_->at(v)+e.w_);
      }
    }

    if (!is_updated)
      break;
  }
}
void Question2::exec() {
  initialize();
  bellman_ford_algo();
}
}  // namespace chapter14
