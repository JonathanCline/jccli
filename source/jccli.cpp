#include <jccli/jccli.hpp>

#include <list>
#include <string>
#include <vector>
#include <ranges>
#include <cstdlib>
#include <algorithm>
#include <string_view>

namespace jc
{
	struct ArgumentParser::ArgumentData
	{
		std::string name{};
		std::string help{};

		std::vector<std::string> aliases{};
		std::vector<char> char_aliases{};

		ArgumentData() = default;
	};
	
	ArgumentParser::Argument& ArgumentParser::Argument::set_help(const char* _message)
	{
		this->data_->help = _message;
		return *this;
	};
	ArgumentParser::Argument& ArgumentParser::Argument::set_name(const char* _name)
	{
		// Add name to aliases
		if (this->data_->aliases.empty())
		{
			this->data_->aliases.push_back(_name);
		}
		else
		{
			// Or replace the exiting alias for the old name
			std::ranges::replace(this->data_->aliases, this->data_->name, _name);
		};

		// Then set the name
		this->data_->name = _name;
		return *this;
	};
	ArgumentParser::Argument& ArgumentParser::Argument::add_alias(const char* _alias)
	{
		this->data_->aliases.push_back(_alias);
		return *this;	
	};
	ArgumentParser::Argument& ArgumentParser::Argument::add_alias(char _alias)
	{
		this->data_->char_aliases.push_back(_alias);
		return *this;	
	};



	struct ArgumentParser::ArgumentStorageData
	{
		std::string description = "";
		std::list<ArgumentParser::ArgumentData> args;

		ArgumentStorageData() = default;
	};
	
	void ArgumentParser::ArgumentStorageDeleter::operator()(ArgumentStorageData* _ptr) const
	{
		delete _ptr;
	};



			





	ArgumentParser::Argument ArgumentParser::add_argument(const char* _name)
	{
		this->storage_->args.emplace_back();
		auto _arg = Argument(&this->storage_->args.back());
		_arg.set_name(_name);
		return _arg;
	};

	ArgumentParser::ParsedArgs ArgumentParser::parse_args(int _nargs, const char* _vargs[])
	{
		auto _parsedArgs = ParsedArgs();

		for (int n = 0; n != _nargs; ++n)
		{
			if (!_vargs[n])
			{
				// Should never happen
				// TODO : Report error
				abort();
			};

			auto _arg = std::string_view(_vargs[n]);
			if (_arg.starts_with("--"))
			{
				// Option name?
				_arg.remove_prefix(2);
				if (_arg.empty())
				{
					// Unexpected syntax, no options specified
					// TODO : Report error
					abort();
				};

				// Find matching



			}
			else if (_arg.starts_with('-'))
			{
				// One or more single option characters?
				_arg.remove_prefix(1);
				if (_arg.empty())
				{
					// Unexpected syntax, no options specified
					// TODO : Report error
					abort();
				};


			}
			else
			{
				// Positional argument?

			}
		};


		return _parsedArgs;
	};

	
	ArgumentParser::ArgumentParser() :
		storage_( new ArgumentStorageData{} )
	{};

	ArgumentParser::ArgumentParser(const char* _description) :
		ArgumentParser()
	{
		this->storage_->description = (_description)? _description : "";
	};
};
