#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../hash_table.h"

void assert_str_eq(char *expected, char *actual) {
	if (actual == NULL) {
		fprintf(stderr, "ASSERTION FAILED: Expected: %s, Got: NULL\n", expected);

		exit(1);
	}

	if (strcmp(expected, actual) != 0) {
		fprintf(stderr, "ASSERTION FAILED: Expected: %s, Got: %s\n", expected, actual);

		exit(1);
	}

	printf("ASSERTION SUCCEEDED: Expected: %s, Got: %s\n", expected, actual);
}

void assert_int_eq(int expected, int actual) {
	if (expected != actual) {
		fprintf(stderr, "ASSERTION FAILED: Expected: %d, Got: %d\n", expected, actual);

		exit(1);
	}

	printf("ASSERTION SUCCEEDED: Expected: %d, Got: %d\n", expected, actual);
}

void assert_null(void *value) {
	if (value != NULL) {
		fprintf(stderr, "ASSERTION FAILED: Expected: NULL, Got: %p\n", value);

		exit(1);
	}

	printf("ASSERTION SUCCEEDED: Expected: NULL, Got: NULL\n");
}

void assert_not_null(void *value) {
	if (value == NULL) {
		fprintf(stderr, "ASSERTION FAILED: Expected value, Got: NULL\n");

		exit(1);
	}

	printf("ASSERTION SUCCEEDED: Expected value, Got: %p\n", value);
}

int main() {
	hash_table_t *hash_table = hash_table_init(30);

	assert_int_eq(30, hash_table->map_size);
	assert_null(hash_table->buckets[0]);

	hash_table_insert(hash_table, "my_key", "my_value test");
	hash_table_insert(hash_table, "myke", "my_value test 2");
	hash_table_insert(hash_table, "1-jK_d4VoOR!i", "1-jK_d4VoOR!i VALUE");
	hash_table_insert(hash_table, "l*^=o_}9C$m}r", "l*^=o_}9C$m}r VALUE");
	hash_table_insert(hash_table, "-p,:+X??x@H'P", "-p,:+X??x@H'P VALUE");
	hash_table_insert(hash_table, "1,'J1e9|bl'>R", "1,'J1e9|bl'>R VALUE");
	hash_table_insert(hash_table, "-<(#@.&*fJA8Y", "-<(#@.&*fJA8Y VALUE");
	hash_table_insert(hash_table, ";dJX'L<rh}Dq$", ";dJX'L<rh}Dq$ VALUE");
	hash_table_insert(hash_table, "Uc-Dujw.8K'*c", "Uc-Dujw.8K'*c VALUE");
	hash_table_insert(hash_table, "_lsQ8WHKOBzFo", "_lsQ8WHKOBzFo VALUE");
	hash_table_insert(hash_table, "IQUzS}+5!|`{n", "IQUzS}+5!|`{n VALUE");
	hash_table_insert(hash_table, "5(p;&!r;sRs)", " 5(p;&!r;sRs) VALUE");
	hash_table_insert(hash_table, "d^X=_vnE^;s$b", "d^X=_vnE^;s$b VALUE");
	hash_table_insert(hash_table, "Ay0HrXpS&&y8K", "Ay0HrXpS&&y8K VALUE");
	hash_table_insert(hash_table, "3@7dZr3~=#", "   3@7dZr3~=# VALUE");
	hash_table_insert(hash_table, "hFntw}k{T~3)K", "hFntw}k{T~3)K VALUE");
	hash_table_insert(hash_table, "QjA252VRrb5a-", "QjA252VRrb5a- VALUE");
	hash_table_insert(hash_table, "+'n+5~5G*VKV*", "+'n+5~5G*VKV* VALUE");
	hash_table_insert(hash_table, "/k3zpe|esUl@c", "/k3zpe|esUl@c VALUE");
	hash_table_insert(hash_table, "G43bDi)t`bk6v", "G43bDi)t`bk6v VALUE");
	hash_table_insert(hash_table, "DguHA1RM8I,ov", "DguHA1RM8I,ov VALUE");
	hash_table_insert(hash_table, "!!_:~usZ/QG3B", "!!_:~usZ/QG3B VALUE");
	hash_table_insert(hash_table, "GWeIF%Dn2mhYd", "GWeIF%Dn2mhYd VALUE");
	hash_table_insert(hash_table, ":LG~5k^oxL>9o", ":LG~5k^oxL>9o VALUE");
	hash_table_insert(hash_table, "s-oZHU%4leILF", "s-oZHU%4leILF VALUE");
	hash_table_insert(hash_table, "|DQ|~H7M;(Iu%", "|DQ|~H7M;(Iu% VALUE");
	hash_table_insert(hash_table, "CdgoybqdF(-9+", "CdgoybqdF(-9+ VALUE");
	hash_table_insert(hash_table, "2eGo!KvO>c'*2", "2eGo!KvO>c'*2 VALUE");
	hash_table_insert(hash_table, "S?X!utqMvKX9L", "S?X!utqMvKX9L VALUE");

	assert_not_null(hash_table_get(hash_table, "my_key"));
	assert_not_null(hash_table_get(hash_table, "myke"));

	assert_null(hash_table_get(hash_table, "this key doesn't exist"));
	assert_null(hash_table_get(hash_table, "fjoiasjfoi"));
	assert_null(hash_table_get(hash_table, "jfoiasy1241"));

	assert_str_eq("my_value test", hash_table_get(hash_table, "my_key"));
	assert_str_eq("my_value test 2", hash_table_get(hash_table, "myke"));
	assert_str_eq("1-jK_d4VoOR!i VALUE", hash_table_get(hash_table, "1-jK_d4VoOR!i"));
	assert_str_eq("l*^=o_}9C$m}r VALUE", hash_table_get(hash_table, "l*^=o_}9C$m}r"));
	assert_str_eq("-p,:+X??x@H'P VALUE", hash_table_get(hash_table, "-p,:+X??x@H'P"));
	assert_str_eq("1,'J1e9|bl'>R VALUE", hash_table_get(hash_table, "1,'J1e9|bl'>R"));
	assert_str_eq("-<(#@.&*fJA8Y VALUE", hash_table_get(hash_table, "-<(#@.&*fJA8Y"));
	assert_str_eq(";dJX'L<rh}Dq$ VALUE", hash_table_get(hash_table, ";dJX'L<rh}Dq$"));
	assert_str_eq("Uc-Dujw.8K'*c VALUE", hash_table_get(hash_table, "Uc-Dujw.8K'*c"));
	assert_str_eq("_lsQ8WHKOBzFo VALUE", hash_table_get(hash_table, "_lsQ8WHKOBzFo"));
	assert_str_eq("IQUzS}+5!|`{n VALUE", hash_table_get(hash_table, "IQUzS}+5!|`{n"));
	assert_str_eq(" 5(p;&!r;sRs) VALUE", hash_table_get(hash_table, "5(p;&!r;sRs)"));
	assert_str_eq("d^X=_vnE^;s$b VALUE", hash_table_get(hash_table, "d^X=_vnE^;s$b"));
	assert_str_eq("Ay0HrXpS&&y8K VALUE", hash_table_get(hash_table, "Ay0HrXpS&&y8K"));
	assert_str_eq("   3@7dZr3~=# VALUE", hash_table_get(hash_table, "3@7dZr3~=#"));
	assert_str_eq("hFntw}k{T~3)K VALUE", hash_table_get(hash_table, "hFntw}k{T~3)K"));
	assert_str_eq("QjA252VRrb5a- VALUE", hash_table_get(hash_table, "QjA252VRrb5a-"));
	assert_str_eq("+'n+5~5G*VKV* VALUE", hash_table_get(hash_table, "+'n+5~5G*VKV*"));
	assert_str_eq("/k3zpe|esUl@c VALUE", hash_table_get(hash_table, "/k3zpe|esUl@c"));
	assert_str_eq("G43bDi)t`bk6v VALUE", hash_table_get(hash_table, "G43bDi)t`bk6v"));
	assert_str_eq("DguHA1RM8I,ov VALUE", hash_table_get(hash_table, "DguHA1RM8I,ov"));
	assert_str_eq("!!_:~usZ/QG3B VALUE", hash_table_get(hash_table, "!!_:~usZ/QG3B"));
	assert_str_eq("GWeIF%Dn2mhYd VALUE", hash_table_get(hash_table, "GWeIF%Dn2mhYd"));
	assert_str_eq(":LG~5k^oxL>9o VALUE", hash_table_get(hash_table, ":LG~5k^oxL>9o"));
	assert_str_eq("s-oZHU%4leILF VALUE", hash_table_get(hash_table, "s-oZHU%4leILF"));
	assert_str_eq("|DQ|~H7M;(Iu% VALUE", hash_table_get(hash_table, "|DQ|~H7M;(Iu%"));
	assert_str_eq("CdgoybqdF(-9+ VALUE", hash_table_get(hash_table, "CdgoybqdF(-9+"));
	assert_str_eq("2eGo!KvO>c'*2 VALUE", hash_table_get(hash_table, "2eGo!KvO>c'*2"));
	assert_str_eq("S?X!utqMvKX9L VALUE", hash_table_get(hash_table, "S?X!utqMvKX9L"));

	hash_table_delete(hash_table, "my_key");

	assert_str_eq("my_value test 2", hash_table_get(hash_table, "myke"));
	assert_null(hash_table_get(hash_table, "my_key"));
}
