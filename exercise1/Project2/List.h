#pragma once
#include <iostream>
#include <memory>


	struct ListNode {
		int val;
		//ListNode* next;
		std::shared_ptr<ListNode> next;
		ListNode(int x) : val(x), next(nullptr) {}
	};


	struct LinkList {
		std::shared_ptr<ListNode> m_head = std::shared_ptr<ListNode>(new ListNode(0));
		//ListNode* m_head = new ListNode(0); 

		LinkList(int v[], int size) {			
			for (int i{ size - 1 }; i > -1 ; i--)
				insert(m_head, v[i]);
		}
		~LinkList()
		{
			remove(m_head);
		}

		void remove(std::shared_ptr<ListNode> pNode)//ListNode* pNode
		{
			if (!pNode)
				return;
			remove(pNode->next);
		    pNode.reset();
		}

		int size()
		{
			int count{};
			if (!m_head->next)
				return count;
			std::shared_ptr<ListNode> s = m_head->next;//ListNode* s
			while (s)
			{
				count++;
				s = s->next;
			}
			return count;
		}



		void erase(int x)
		{
			if (!m_head->next)
				return;
			std::shared_ptr<ListNode> e = m_head;
			while (e->next)
			{
				if (e->next->val == x)
				{
					std::shared_ptr<ListNode> temp = e->next;
					e->next = e->next->next;
					temp.reset();
					continue;
				}
				e = e->next;
			}
			if (e->val == x)
			{
				e.reset();
			}
		}


		//after the given node
		void insert(std::shared_ptr<ListNode> root, int v)//ListNode*  root
		{
			std::shared_ptr<ListNode> temp = std::shared_ptr<ListNode>(new ListNode(v));
			if (root)
			{
				temp->next = root->next;
				root->next = temp;
			}
			else
			{
				insert(m_head,v);
			}
		}

		// return fist node that has value x 
		std::shared_ptr<ListNode> find(int x)
		{
			if (!m_head->next)
				return nullptr;

			std::shared_ptr<ListNode> f = m_head->next;
			while (f)
			{
				if (f->val == x)
				{
					return f;
				}
				f = f->next;
			}

			return nullptr;
		}

	};

	std::ostream& operator<< (std::ostream& os, const LinkList& lst)
	{
		std::shared_ptr<ListNode> output = lst.m_head->next;
		if (!output)
		{
			os << "List is empty.";
			return os;
		}
		while (output->next != nullptr)
		{
			os << output->val << "->";
			output = output->next;
		}
		os << output->val;
		return os;
	}
