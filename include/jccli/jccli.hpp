#pragma once

/** @file */

#include <memory>

namespace jc
{

	class ArgumentParser
	{
	private:

		struct ArgumentData;

		struct ArgumentStorageData;
		friend ArgumentStorageData;

		struct ArgumentStorageDeleter
		{
			void operator()(ArgumentStorageData* _ptr) const;
		};
		using ArgumentStorage = std::unique_ptr<ArgumentStorageData, ArgumentStorageDeleter>;

	public:

		struct Argument
		{
		public:
			Argument& set_name(const char* _name);
			Argument& set_help(const char* _message);
			Argument& add_alias(const char* _alias);
			Argument& add_alias(char _alias);

		private:
			Argument(ArgumentParser::ArgumentData* _data) :
				data_(_data)
			{};
			friend ArgumentParser;

			ArgumentParser::ArgumentData* data_;
		};
		friend Argument;

		Argument add_argument(const char* _name);


		class ParsedArgs
		{
		public:


		private:
			ParsedArgs() = default;
			friend ArgumentParser;
		};

		ParsedArgs parse_args(int _nargs, const char* _vargs[]);


		ArgumentParser();
		ArgumentParser(const char* _description);

	private:
		ArgumentStorage storage_;
	};
};

